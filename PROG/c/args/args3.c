#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]){
  
  int aflag, opt;
  int c;
  char *cvalue = NULL;
  int index;
  //int nsecs, tfnd;

  while ((c = getopt(argc, argv, "ab:")) != -1) {
    switch (c){
      case 'a':
       aflag = 1;
       break;
      case 'b':
       cvalue = optarg;     //this one requires an arg 
       break;
      case '?':
        if (optopt == 'c')
        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
          else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
          else
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
          return 1;
        default:
          abort ();
        }
      }
      
     ////
      /*
       printf ("aflag = %d, cvalue = %s\n" ,aflag, cvalue);
     
       for (index = optind; index < argc; index++)
         printf ("Non-option argument %s\n", argv[index]);
         
       return 0;
     }
     */
     
      
  fprintf(stderr, "Usage: %s [-a] name\n", argv[0]);
  exit(EXIT_FAILURE);
}
  
  // if ok call function and stick the argument into it
 



