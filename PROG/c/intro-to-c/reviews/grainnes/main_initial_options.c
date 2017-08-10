#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>

#define CHUNKSIZE 1024
#define MAXNAMESIZE 256

// Implement find
// functions


int main(int argc, char *argv[]) {
// variables
  int findtype, findname;
  int opt;
  char *noption;
  char *toption;

// the main code is here onwards

// the switch, use the findname and findtype to alter the way that find works.
while ((opt = getopt(argc, argv, "n:t:")) != -1) {
  switch (opt) {
  case 'n':
    findname = 1;
    noption = optarg;
    printf("flag n is set as %s\n", noption);
    break;
  case 't':
    findtype = 1;
    toption = optarg;
    printf("flag t is set as %s\n", toption);
    break;
  default:
      fprintf(stderr, "Usage: %s [-t <type>] [-n <name>]\n",
             argv[0]);
             exit(EXIT_FAILURE);
               }
}


exit(EXIT_SUCCESS);
}
