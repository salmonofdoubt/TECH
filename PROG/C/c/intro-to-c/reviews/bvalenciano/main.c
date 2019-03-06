#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>
#include "find.h"

int main (int argc, char **argv){

  // leczb: argc is always 1 or more, as the first argument (argv[0]), is the
  //        program name. Try to print it! :)
  //
  if (argc == 1) open_directory(".");
  else open_directory(argv [1]);

  exit(EXIT_SUCCESS);
}
