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
  char  has_name_filter = 0;
  char  has_type_filter = 0;
  char* pathname;
  int opt;
  char* name_filter;
  char* type_filter;
  name_filter = (char*) malloc(1000);
  type_filter = (char*) malloc(1000);
  while ((opt = getopt(argc, argv, "n:t:")) != -1) {
    switch (opt) {
      case 'n': 
        has_name_filter = 1;
        strcpy(name_filter, optarg); 
        break;
      case 't':
        has_type_filter = 1;
        strcpy(type_filter, optarg); 
        break;
      default: break;
    }
  }
  
  pathname = (char*) malloc(1024);
  pathname = (argc > optind) ? argv[optind] : ".";
  printf("Name filter: %s\n", name_filter);  
  printf("Type filter: %s\n", type_filter);  
  printf("Pathname: %s\n", pathname);  
  if (chdir(pathname)) 
    fail_miserably("Sorry mate, wrong directory");
  print_dir( pathname, 
             has_name_filter, 
             name_filter,
             has_type_filter, 
             type_filter );
}