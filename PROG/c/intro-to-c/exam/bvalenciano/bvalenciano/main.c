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

  if (argc == 1) open_directory(".");
  else open_directory(argv [1]);

  exit(EXIT_SUCCESS);
}

