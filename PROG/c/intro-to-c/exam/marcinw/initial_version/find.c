#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "filetricks.h"

void fail_miserably(const char* message) {
  puts(message);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  char* pathname;
  pathname = (char*) malloc(1024);
  pathname = (argc > 1) ? argv[1] : ".";
  chdir(pathname);
  print_dir(pathname);
}