#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "visit.h"

#define CHUNKSIZE 1024
#define MAXNAMESIZE 256

/* myfind should work similar to find */


int main(int argc, char *argv[]) {
  int findtype, findname;
  int opt;
  char *noption;
  char *toption;

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
