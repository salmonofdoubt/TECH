#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "filetricks.h"

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
}

void print_dir( const char* path, 
                char has_name_filter, 
                const char* name_filter,
                char has_type_filter, 
                const char* type_filter,
                uid_t uid,
                gid_t gid,
                long min_size ) {
  DIR*   directory;
  struct dirent* entry;
  struct stat* buff;
  char satisfies_options;
  char*  file_type;
  
  buff = malloc(sizeof(struct stat));
  directory = opendir(".");

  if (directory == NULL)
    fail_miserably("Sorry mate, invalid directory");

  while(entry = readdir(directory)) {
    if (entry->d_name[0] != '.') {
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
          chdir(entry->d_name);
          print_dir( get_full_path(path, entry->d_name), 
                     has_name_filter, 
                     name_filter,
                     has_type_filter, 
                     type_filter,
                     uid,
                     gid,
                     min_size );
        }
      }
    }
  }
  if (closedir(directory) == -1) 
    fail_miserably("Problem: could not close directory");
  free(buff);
  chdir("..");
}