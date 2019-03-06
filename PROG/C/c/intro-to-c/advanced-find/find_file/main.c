//man 1 find equivalent
//implement getopt()

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>           
#include <dirent.h>

#include "recursive_filter.h"

//watchout what to put in .h 
void displaymatches(){
  }
                                  
int main(int argc, char *argv[]) {                //knows argc(count), and argv(value)
  
  DIR *dirp;
  struct dirent *dirent;
  
  int d_flag = 0;        //dir flag          
  char *fvalue = NULL;   //file value
  int index;
  int f;                 //file flag
     
  opterr = 0;
     
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
          
  //reads dir content from structure 'dirent'
  while ((dirent = readdir(dirp)) != NULL) {
  //exclude hidden files as well as dirs. Identifies dirs by means of d_type
  if (dirent->d_name[0] != '.' && dirent->d_type > 4){     
      printf("%s....%d\n", dirent->d_name, dirent->d_type);    //no more directories here  
      }
    }  
   exit(EXIT_SUCCESS);
}

  //Next: whilst doing this, stick file names into an array
  /*now add further support for -n <filename> 
  Only print filenames that match <name>
  Use exact match of directory entry name, not the full path.
  */
    
  //passing the 2nd cml arg?
  
  /*
  dirp2 = opendir(argv[2]);                         //the file name to be found argv[2] 
    if (dirp2 == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  */
  
  //Then: iterate the array for the given filename, and print only those.  
  
  
  
     /*Next stage:
     - reads filenames from structure 'dirent', print only matching filenames
     - needs a recursive function
     - so whilst doing this, stick file names into an array

     - passing the 2nd cml arg?
    
     - Then: iterate the array for the given filename, and print only those.   
      */
        
  

