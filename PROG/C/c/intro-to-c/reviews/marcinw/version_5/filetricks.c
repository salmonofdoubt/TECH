// leczb: Minor style comment: "filetricks" sounds a bit off. I would have named
//        this find.c or fileutils.c
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "filetricks.h"

void fail_miserably(const char* message) {
  // leczb: this should print the error message to stderr instead of stdout
  puts(message);
  exit(EXIT_FAILURE);
}

char* get_full_path(const char* path, const char* filename) {
  char* result;
  // leczb: allocating a fixed sized buffer and then using strcpy()
  //        on it is not safe. This is a very common source of security
  //        vulnerabilities. See http://en.wikipedia.org/wiki/Buffer_overflow
  //        for the details.
  //        You either have to use strncpy() (passing in the number of available
  //        bytes in the buffer) or malloc() the buffer after calculating the
  //        required size.
  result = (char*) malloc(4096);
  strcpy(result, path);
  if (path[strlen(path) - 1] != '/') strcat(result, "/");
  strcat(result, filename);
  return result;
}


char get_filetype(struct stat* buff) {
  if (S_ISBLK(buff->st_mode))  return 'b';
  if (S_ISCHR(buff->st_mode))  return 'c';
  if (S_ISDIR(buff->st_mode))  return 'd';
  if (S_ISFIFO(buff->st_mode)) return 's';
  if (S_ISREG(buff->st_mode))  return 'f';
  if (S_ISLNK(buff->st_mode))  return 'l';
  else return 0;
}

// leczb: Style: This looks like a very long argument list.
//               Alternative solution: you can
//               declare a print_dir_opts structure with these fields and
//               either require such a struct or a pointer to such a struct
//               as input for this function.
char print_dir( const char* path, 
                char has_name_filter, 
                const char* name_filter,
                char has_type_filter, 
                const char* type_filter,
                uid_t uid,
                gid_t gid,
                // leczb: long is not wide enough to describe large filesizes.
                //        In fact, the largest file size you can pass in
                //        via a long variable is (2 GiB - 1).
                //        size_t should be used, or better yet, off_t
                //        (see the struct stat part of man 2 stat).
                long min_size,
                int  max_recursion ) {
  
  char       status = 0;
  DIR*       directory;
  struct     dirent* entry;
  struct     stat* buff;
  char       satisfies_options;
  // leczb: it's more straightforward to pass the current recursion level
  //        as a function argument. If you do that, you don't have to
  //        do the ++ / -- dance, just call the function with
  //        (current value + 1).
  static int recursion_level = 0;
  
  /* If we're too deep... skip */ 
  if (max_recursion > -1 && recursion_level > max_recursion)
    return 0;
    
  recursion_level++;
  
  // leczb: It's easier to just declare buff as struct stat instead of struct
  //        stat *. In that case, you don't have to malloc() space for it and
  //        it gets freed up automatically, when it goes out of scope.
  //        Dangerous bug: you are not checking for NULL pointer from malloc.
  buff = malloc(sizeof(struct stat));
  
  if ((directory = opendir(".")) == NULL) {
    // leczb: This should be printed to stderr with the name of directory you
    //        could not open and the result from strerror(errno) appended.
    puts("Can not open directory");
    // leczb: You have a memory leak here: you are not freeing up buff.
    return 0;
  }

  while((entry = readdir(directory)) != 0) {
    if (strcmp(entry->d_name, ".") & strcmp(entry->d_name, "..")) {
      int stat_status = stat(entry->d_name, buff);
      // leczb: You are not handling the error. If stat() fails, an error
      //        message should be printed (see above).
      if (!stat_status) {
        // If there is a name filter set, make sure it is satisfied
        // leczb: This expression looks a bit unnatural. How about applying De
        //        Morgan's law, to turn it into:
        //          satisfies_options = has_name_filter && strcmp(...) == 0;
        satisfies_options = (!has_name_filter || !strcmp(entry->d_name, name_filter));
        // If there is a type filter set, make sure it is satisfied
        satisfies_options &= (!has_type_filter || (strchr(type_filter, get_filetype(buff)) != NULL));
        // If there is a uid filter set, make sure it is satisfied
        // leczb: I doubt that the uid variable can ever take a negative value. Most
        //        probably, the uid_t type is typedef'd to an unsigned integer
        //        type (uint32_t).
        satisfies_options &= (uid == -1) || uid == buff->st_uid;
        // If there is a gid filter set, make sure it is satisfied
        // leczb : Same as above.
        satisfies_options &= (gid == -1) || gid == buff->st_gid;
        // If there is a size filter set, make sure it is satisfied
        satisfies_options &= (min_size == -1) || buff->st_size >= min_size;
        if (satisfies_options)
          printf("%s\n", get_full_path(path, entry->d_name));
        if (get_filetype(buff) == 'd') {
          if (!chdir(entry->d_name)) {
            status |= print_dir( get_full_path(path, entry->d_name), 
                                 has_name_filter, 
                                 name_filter,
                                 has_type_filter, 
                                 type_filter,
                                 uid,
                                 gid,
                                 min_size,
                                 max_recursion );
          }
          else if(satisfies_options)
            // leczb: You can't assume that chdir() failed due to "no access".
            //        You have to examine the value of errno and compare it
            //        expected values (see the ERRORS section in man chdir).
            //        If you don't care, just print the error using strerror().
            printf("%s <no access>\n", get_full_path(path, entry->d_name));
        }
      }
    }
  }
  if (closedir(directory) == -1) 
    // leczb: Same comment as above (stderr + strerror())
    fail_miserably("Problem: could not close directory");
  free(buff);
  // leczb: I can't see where you are using the value of status. Is it something
  //        you wanted to use, but never got around to actually implement?
  status |= chdir("..");
  recursion_level--;
  // leczb: 1 is a magic number. It's best to #define such magic constants.
  //        Something like
  //          #define SUCCESS 1
  return 1;
}
