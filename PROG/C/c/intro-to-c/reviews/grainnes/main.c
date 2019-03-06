#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "visit.h"

// leczb: You have the same #define entries in visit.h
#define CHUNKSIZE 1024
#define MAXNAMESIZE 256

/* myfind should work similar to find */


int main(int argc, char *argv[]) {
  int findtype, findname;
  int opt;
  char *noption;
  char *toption;

  // leczb: You can't assume that argv[1] is actually present.
  //        You need to check argc first. This is going to result
  //        in a segfault if your program is called with no arguments.
  //        It should be something like:
  //          char *path;
  //          if (argc < 2) {
  //            path = ".";
  //          } else {
  //            path = argv[1];
  //          }
  if (chdir(argv[1]) == -1) {
    chdir(".");
  } else {
    chdir(argv[1]);
  }


// the switch, use the findname and findtype to alter the way that myfind should work.
while ((opt = getopt(argc, argv, "n:t:")) != -1) {
  switch (opt) {
  case 'n':
    findname = 1;
    noption = optarg;
//    printf("flag n is set as %s\n", noption);
    break;
  case 't':
    findtype = 1;
    toption = optarg;
//    printf("flag t is set as %s\n", toption);
    break;
  default:
      fprintf(stderr, "Usage: %s <directory>  Optional :[-t <type>] [-n <name>]\n",
             argv[0]);
             exit(EXIT_FAILURE);
               }
}

  visit(argv[1]);

exit(EXIT_SUCCESS);
}
