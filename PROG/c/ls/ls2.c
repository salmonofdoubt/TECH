/*
1. implement 'ls -1'
readd directory entries from given dir 
(1st arg to the command)
print the file names

2. implement 'ls -l' read 'el'
hints:

man 3 opendir
man 3 readdir
man 2 stat
man 2 qsort (optional)

SYNOPSIS
       #include <sys/types.h>
       #include <dirent.h>
       DIR *opendir(const char *name);
       DIR *fdopendir(int fd);

man 2 stat

next: implement 
man strace 
man ltrace (on executable file, no ext)
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <unistd.h> 


int main(int argc, char *argv[]) {
  DIR *dir;    
  //dir points to dp
  dir = opendir("/home/abaumann/sreu/c/ls");
  //dir opens current dir
  struct dirent *dp;
  //in structure, point dp to dirent
    
  while ((dp = readdir(dir)) != NULL){
  //while dp readdir is not NULL...
  if (dp->d_name[0] != '.'){
    
  //next: show stats of these files, #include <unistd.h>, man 2 stat
  struct stat statbuf;
  //
  off_t st_size; 
  /* total size, in bytes */
  stat(dp->d_name, &statbuf);
  
  //...and if the current result does not start with '.': 
  printf("%s\t\t %lld\n ", dp->d_name, (long long)statbuf.st_size);  
  }  
  //ok until here
 }
}

 




