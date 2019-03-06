#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "filetricks.h"

void fail_miserably(const char* message) {
  puts(message);
  exit(EXIT_FAILURE);
}

char* get_full_path(const char* path, const char* filename) {
  char* result;
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

char print_dir( const char* path, 
                char has_name_filter, 
                const char* name_filter,
                char has_type_filter, 
                const char* type_filter,
                uid_t uid,
                gid_t gid,
                long min_size,
                int  max_recursion ) {
  
  char       status = 0;
  DIR*       directory;
  struct     dirent* entry;
  struct     stat* buff;
  char       satisfies_options;
  static int recursion_level = 0;
  
  /* If we're too deep... skip */ 
  if (max_recursion > -1 && recursion_level > max_recursion)
    return 0;
    
  recursion_level++;
  
  buff = malloc(sizeof(struct stat));
  
  if ((directory = opendir(".")) == NULL) {
    puts("Can not open directory");
    return 0;
  }

  while((entry = readdir(directory)) != 0) {
    if (strcmp(entry->d_name, ".") & strcmp(entry->d_name, "..")) {
      int stat_status = stat(entry->d_name, buff);
      if (!stat_status) {
        // If there is a name filter set, make sure it is satisfied
        satisfies_options = (!has_name_filter || !strcmp(entry->d_name, name_filter));
        // If there is a type filter set, make sure it is satisfied
        satisfies_options &= (!has_type_filter || (strchr(type_filter, get_filetype(buff)) != NULL));
        // If there is a uid filter set, make sure it is satisfied
        satisfies_options &= (uid == -1) || uid == buff->st_uid;
        // If there is a gid filter set, make sure it is satisfied
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
            printf("%s <no access>\n", get_full_path(path, entry->d_name));
        }
      }
    }
  }
  if (closedir(directory) == -1) 
    fail_miserably("Problem: could not close directory");
  free(buff);
  status |= chdir("..");
  recursion_level--;
  return 1;
}
