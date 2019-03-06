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
#include <unistd.h> 

// leczb: There's no point in including an empty file
#include "recursive_filter.h"

// leczb: Empty function?
int printmatches(){

  // leczb: return type is int, which is non-void, so you must return an int
  //        value.
}

int main(int argc, char *argv[]) {                
  
  DIR *dirp;
  struct dirent *dirent;
  char *filename;
  int i;
   
  int dir_flag = 0;       //dir flag          
  char *fvalue = NULL;    //file value
  int index;
  int file_flag;          //file flag
  opterr = 0;

  //takes two cml args, elf and dir 
  if (argc < 2) {
    // leczb: This is not what the description says at the beginning of the
    //        file.
    //        It should be:
    //          "Usage: %s [dir]\n"
    //        ...and if no dir was supplied by the user, "." should be assumed.
    printf("Usage: %s <dir>\n", argv[0]);         
    exit(EXIT_FAILURE);
    // leczb: Style: wrong indentation. Should be below the "if"
      }  
     
  // leczb: Style: There shouldn't be commented out code.
  /*
    while ((f = getopt (argc, argv, "df:")) != -1)
    switch (f){
      case 'd':
        d_flag = 1;
        break;
      case 'f':
        fvalue = optarg;
        break;
      case '?':
        if (optopt == 'f')
        fprintf (stderr, "Option -%c needs argument.\n", optopt);
          else if 
            (isprint (optopt))
            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
          else
            fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        }
     
       for (index = optind; index < argc; index++) {
         if (argc == 0)
         printf ("No such argument %s\n", argv[index]);
       return 0;
     }
  */

  dirp = opendir(argv[1]); 
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  
  
  //So this goes into the printmatches function
  // leczb: ^^^ you should have put it there then.
  while ((dirent = readdir(dirp)) != NULL) {
  //exclude hidden files as well as dirs. Identifies dirs by means of d_type
  // leczb: ^^^ this wasn't part of the requirement at all. The only requirement
  //        was to filter out the '.' and '..' entries.
    if (dirent->d_name[0] != '.' && dirent->d_type > 4){     
      printf("%s...%d\n", dirent->d_name, dirent->d_type);    //no more directories here  
      // leczb: This is incorrect. sizeof(char) is by definition 1. You are
      //        always allocating 1 byte of memory for filename.
      filename = (char *)malloc(sizeof(char));
      
    //passing the 2nd cml arg?
    //strcpy() > array
    // 
    //Then: iterate the array for the given filename, and print only those.  
    
     /*Next stage:
     - reads filenames from structure 'dirent', print only matching filenames
     - needs a recursive function
     - so whilst doing this, stick file names into an array

     - passing the 2nd cml arg?
    
     - Then: iterate the array for the given filename, and print only those.   
      */
        }
    }
  

  exit(EXIT_SUCCESS);
}
