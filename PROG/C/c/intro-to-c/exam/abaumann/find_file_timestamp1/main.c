/*
man 1 find
Initial version (required):
just takes a single path argument and prints the filenames under that path, recursively (like find does, when called with no filtering arguments)
if called without arguments, it assumes "." was passed in (the current directory, that is)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

#include "recursive_filter.h"

//watchout what to put in .h 

int outside(){
  
  }


int main(int argc, char *argv[]) {
  
  DIR *dirp;
  struct dirent *dirent;

  //takes two cml args, elf and dir 
  if (argc < 2) {
    printf("Usage: %s <dir>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  dirp = opendir(argv[1]);
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  
  //Initial stage: reads filenames from structure 'dirent', prints d_name
  while ((dirent = readdir(dirp)) != NULL) {
    //exclude hidden files
    if (dirent->d_name[0] != '.'){
    printf("%s\n", dirent->d_name);
    }
  }
  
  
  /*Next stage: reads filenames from structure 'dirent', prints d_name
  //needs a recursive function
  while ((dirent = readdir(dirp)) != NULL) {
    printf("%s\n", dirent->d_name);
  }
  
  dirp = opendir(argv[2]);
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  */
  //////
  /*
  filenames = (char *) malloc(buffsize * NAMESIZE);
  while ((dirent = readdir(dirp)) != NULL) {
    strncpy(filenames + NAMESIZE * entries, dirent->d_name, NAMESIZE);
    entries++;
    if (entries == buffsize) {
      buffsize += CHUNKSIZE;
      filenames = (char *) realloc(filenames, buffsize * NAMESIZE);
    }
  }
  */
  
/*now add further support for -n <filename> 
Only print filenames that match <name>
Use exact match of directory entry name, not the full path.
*/


  exit(EXIT_SUCCESS);
}
