//#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>            //in order to use getopt()
     
int main (int argc, char **argv) {
  
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
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 1;
      default:
        abort ();
      }
     
      for (index = optind; index < argc; index++)
         printf ("No such argument %s\n", argv[index]);
       return 0;
}

