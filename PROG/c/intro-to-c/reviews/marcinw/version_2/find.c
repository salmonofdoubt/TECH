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
  char  has_filter = 0;
  char* pathname;
  int opt;
  char* filter;
  filter = (char*) malloc(1000);
  while ((opt = getopt(argc, argv, "n:")) != -1) {
    switch (opt) {
      case 'n': 
        has_filter = 1;
        strcpy(filter, optarg); 
        break;
      default: break;
    }
  }
  // printf("Argc: %d\nOptind: %d\n", argc, optind);  
  
  pathname = (char*) malloc(1024);
  pathname = (argc > optind) ? argv[optind] : ".";
  // printf("Filter: %s\n", filter);  
  // printf("Pathname: %s\n", pathname);  
  if (chdir(pathname)) 
    fail_miserably("Sorry mate, wrong directory");
  print_dir(pathname, has_filter, filter);
}