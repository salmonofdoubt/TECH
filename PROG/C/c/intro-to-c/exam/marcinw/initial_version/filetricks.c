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
  result = (char*) malloc(1000);
  strcpy(result, path);
  if (path[strlen(path) - 1] != '/') strcat(result, "/");
  strcat(result, filename);
  return result;
}

char* get_filetype(struct stat* buff) {
  if (S_ISBLK(buff->st_mode))  return "block special file";
  if (S_ISCHR(buff->st_mode))  return "character special file";
  if (S_ISDIR(buff->st_mode))  return "directory";
  if (S_ISFIFO(buff->st_mode)) return "pipe or FIFO special file";
  if (S_ISREG(buff->st_mode))  return "regular file";
  if (S_ISLNK(buff->st_mode))  return "symbolic link";
}

void print_dir(const char* path) {
  DIR*   directory;
  struct dirent* entry;
  struct stat* buff;
  char*  file_type;
  
  buff = malloc(sizeof(struct stat));
  directory = opendir(".");

  if (directory == NULL)
    fail_miserably("Sorry mate, invalid directory");

  while(entry = readdir(directory)) {
    if (entry->d_name[0] != '.') {
      int stat_status = stat(entry->d_name, buff);
      if (!stat_status) {
        file_type = get_filetype(buff);
        printf( "%s\n", 
                get_full_path(path, entry->d_name));
        if (!strcmp(file_type, "directory")) {
          chdir(entry->d_name);
          print_dir(get_full_path(path, entry->d_name));
        }
      }
    }
  }
  if (closedir(directory) == -1) 
    fail_miserably("Problem: could not close directory");
  free(buff);
  chdir("..");
}
