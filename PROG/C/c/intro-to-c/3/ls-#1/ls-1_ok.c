/*
Simple ls implementation. Specify the dir and read it's contents.

see ls -1 (no.):
The numeric digit ``one''.)  Force output to be one entry per line.
This is the default when output is not to a terminal.

Does not compile on Mac, ok on Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  
  DIR *dirp;
/* 
How did we get DIR and *dirp(ointer). 
Also explain the struct:
*/
  struct dirent *dirent;

  if (argc < 2) {
    printf("Usage: %s <dir>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

/* 
opens dir based on 1st argvalue
*/
  dirp = opendir(argv[1]);
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  
/* 
While there is a dir entry, read it and print it
*/
  while ((dirent = readdir(dirp)) != NULL) {
    printf("%s\n", dirent->d_name);
  }

  exit(EXIT_SUCCESS);
}
