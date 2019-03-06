/* file : print_dirs.c */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "print_dirs.h"

/* invaliud usage */
int print_usage(char *my_progname){
  printf("Usage: %s -d <path>\n", my_progname);
  exit(EXIT_FAILURE);
}

/* filter out the dot dirs */
int not_dot(const void *input) {
  return ((strcmp(input, ".") && strcmp(input, "..")));
}

/* open a dir and print contents */
void print_dir(char *p) {
  DIR           *dirp ;
  struct dirent *entry ;
  char           sbuff[4096] = {0};
  size_t         plen = 0;

  dirp = opendir(p) ;
  if (dirp == NULL) {
    perror("opendir");
  }
  else {
    while((entry = readdir(dirp)) != NULL) {  /* cycle through entries in a dir */
      plen  = strlen(entry->d_name);

      if(not_dot(entry->d_name)) {            /* filter out dot_dirs */
        sprintf(sbuff, "%s/%s", p, entry->d_name);

        if( (entry->d_type == 0x4)) {
          printf("%s/%s\n", p, entry->d_name);
          print_dir(sbuff);                   /* recursive call of print_dir */
        }
        else{
          printf("%s/%s\n", p, entry->d_name);
        }
      }
    }
  }
}
