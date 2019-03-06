#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "filetricks.h"

int main(int argc, char* argv[]) {
  char  final_status    = 0;
  char  has_name_filter = 0;
  char  has_type_filter = 0;
  int   max_recursion   = -1;
  uid_t uid = -1;
  gid_t gid = -1;
  long  min_size = -1;
  char* pathname;
  int opt;
  char* name_filter;
  char* type_filter;
  name_filter = (char*) malloc(1000);
  type_filter = (char*) malloc(1000);
  while ((opt = getopt(argc, argv, "n:t:o:g:s:d:")) != -1) {
    switch (opt) {
      case 'n': 
        has_name_filter = 1;
        strcpy(name_filter, optarg); 
        break;
      case 't':
        has_type_filter = 1;
        strcpy(type_filter, optarg); 
        break;
      case 'o':
        uid = (uid_t) atoi(optarg);
        break;
      case 'g':
        gid = (gid_t) atoi(optarg);
        break;
      case 's':
        min_size = atol(optarg);
        break;
      case 'd':
        max_recursion = atoi(optarg);
        break;
      default: 
        fail_miserably("Unknown option");
        break;  
    }
  }
  
  pathname = (char*) malloc(1024);
  pathname = (argc > optind) ? argv[optind] : ".";
  if (chdir(pathname)) 
    fail_miserably("Incorrect directory");
  
  final_status |= print_dir( pathname, 
                             has_name_filter, 
                             name_filter,
                             has_type_filter, 
                             type_filter,
                             uid,
                             gid,
                             min_size,
                             max_recursion );
  exit(EXIT_SUCCESS);
}