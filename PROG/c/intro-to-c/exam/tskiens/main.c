/* file : main.c
* NAME
*   my_find - search for files in a directory hierarchy
*
* SYNOPSIS
*   find [-d <path>]
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "print_dirs.h"

int main(int argc, char **argv) {
  char  *progname = argv[0];
  char  *path = 0;
  int    flag, opt;

  if( argc == 1 ) {
    path = ".";
  }

  while((opt = getopt(argc, argv, "d:")) != -1) {  /* option parsing */
    switch (opt) {
      case 'd' :
        path = optarg;
        break;
      default:
        print_usage(progname);
        exit(EXIT_FAILURE);
        break;
    }
  }

  printf("%s\n", path);   /* print the single dot before going into recursion */
  print_dir(path);        /* recursively print files in dirs */
  exit(EXIT_SUCCESS);
}
