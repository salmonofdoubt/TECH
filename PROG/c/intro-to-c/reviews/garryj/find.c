#include "find.h"

// leczb: Why filename isn't "const char *"?
void PrintEntry(struct dirent *dirent, char *filename, const char *name,
                const int type, const int uid, const int gid, const int size){
  struct stat buf;
  // leczb: Just an idea for optimization: you don't have to stat() if the user
  //        didn't provide filtering conditions that require it.
  lstat(filename, &buf);

  // leczb: Applying De Morgan's law, it can be turned into a more readable
  //        expression (also, 1 line, instead of 3):
  // if (name && strcmp(dirent->d_name, name)) return;
  if (!(name == NULL || !strcmp(dirent->d_name, name))){
    return;
  }
  // leczb: These won't work if you want to look for the root user's or
  //        group's files (uid == 0)
  if (uid && uid != buf.st_uid) return;
  if (gid && gid != buf.st_gid) return;
  // leczb: This looks incorrect. Does it actually work? :)
  //        I would have written it as
  //          if (type && dirent->d_type != type) return;
  //        But this is still dangerous: what if 0 is valid value for d_type?
  if ((type != 0) && (type == dirent->d_type)){
    return;
  }

  printf("%s\n", filename);
}

// leczb: Style: you are passing way too many arguments. You might want to
//               declare a read_dir_opts structure with these fields and
//               either require such a struct or a pointer to such a struct
//               as input.
//               Something like
//                 void ReadDir(DIR *dp, const char *dir,
//                              const struct read_dir_opts *opts)
//               Then refer to the opts as
//               opts->name, opts->type, etc.
void ReadDir(DIR *dp, char *dir, const char depth_set, char depthc,
             const char depth, const char *name, const int type,
             const int uid, const int gid, const int size){
  DIR *child_dp;
  struct dirent *dirent;
  int realloc_size; 
  char *filename;
  ssize_t buffsize;

  while ((dirent=readdir(dp))) {
    filename = malloc(BUFFSIZE);
    // leczb: It's true that malloc()'d space is uninitialized, but
    //        you don't have to zero it out, as it's first used as a
    //        target buffer for snprintf(), which doesn't care what's
    //        in it, just overwrites it.
    //        Anyway, this bzero() doesn't hurt... it's just not required.
    bzero(filename, BUFFSIZE);
    buffsize = BUFFSIZE;
    // leczb: This can be made more readable if you write
    //        if (depth_set && depth >= depthc) return;
    //        Which can be read as "if the current depth has hit the limit..."
    //        Also, you can use negative values to encode the "unset" state,
    //        so you can get rid of the extra variable (see my reference impl.)
    //        Although, yours is more readable ;)
    if ((depth_set && !(depthc < depth))){
      return;
    }
    while ((realloc_size = snprintf(filename, buffsize, "%s/%s", dir,
                                    dirent->d_name)) > buffsize){
      buffsize = realloc_size + buffsize;
      filename = realloc(filename, buffsize);
    }
    // leczb: Style: wrong indentation here.
    
      // leczb: I had to read this condition expression twice to get how it's
      //        working.
      //        I would recommend doing something like this:
      //          if (!(   strcmp(n, ".") == 0
      //                || strcmp(n, "..") == 0)) { ...
      //
      if (strcmp(dirent->d_name, ".") && strcmp(dirent->d_name, "..")){
        PrintEntry(dirent, filename, name, type, uid, gid, size);
        // leczb: d_type is not a flag-field. Its values are 1, 2, 3, etc.
        //        This means, you must use the == operator to test for a certain
        //        value:
        //          if (dirent->d_type == DT_DIR) { ...
        if (dirent->d_type & DT_DIR){
          // leczb: You are opening the dir, but you are not closing it.
          //        This is a filedescriptor leak. Try to set your
          //        filedescriptor limit to something ridiculosly low
          //        and try to run your program against a deep directory
          //        structure to see what happens:
          //          bash # start a new shell, so ulimit only applies to that
          //          mkdir -p /tmp/1/2/3/4/5/6/7/8/9/10/11
          //          ulimit -n 10
          //          ./find /tmp/1
          if ((child_dp = opendir(filename)) != NULL){
            ReadDir(child_dp, filename, depth_set, depthc+1, depth, name, type,
                    uid, gid, size);
          }
        }
      }
    free(filename);
  }
}

// leczb: The too many arguments comment applies here as well.
void Find(int dir_count, char **dirs, const char depth_set, char depthc,
          const char depth, const char *name, const int type, const int uid,
          const int gid, const int size){
  int i;
  DIR *dp;
  for (i=0; i<dir_count; i++){
    if ((dp = opendir(dirs[i]))){
      printf("%s\n", dirs[i]);
//      printf("1");
      ReadDir(dp, dirs[i], depth_set, depthc, depth, name, type, uid, gid,
              size);
    }
    else {
      // leczb: You can't assume opendir() failed due to a nonexistent entry.
      //        You need to call perror() or strerror() to get the error message
      //        corresponding to the current value of the errno global variable.
      //        You have to include <errno.h>. See man 3 strerror.
      printf("find: \'%s\': No such file or directory", dirs[i]);
    }
  }
}
