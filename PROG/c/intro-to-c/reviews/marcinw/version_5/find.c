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
  // leczb: This could have been declared as
  //          char name_filter[1000];
  //        With this, you don't have to malloc() space for it.
  char* name_filter;
  char* type_filter;
  name_filter = (char*) malloc(1000);
  type_filter = (char*) malloc(1000);
  while ((opt = getopt(argc, argv, "n:t:o:g:s:d:")) != -1) {
    switch (opt) {
      case 'n': 
        has_name_filter = 1;
        // leczb: It's not safe to stcpy() into a fixed sized buffer as you
        //        can't know how long the input string is. There will always
        //        be an input string that is longer than your buffer.
        //        See my relevant comment in findtricks.c, line 20.
        strcpy(name_filter, optarg); 
        break;
      case 't':
        has_type_filter = 1;
        strcpy(type_filter, optarg); 
        break;
      case 'o':
        // leczb: atoi() is not the correct function to use as int is too small
        //        to hold all possible uid values (uids are unsigned 32 bit
        //        integers on modern Unix systems)
        //        atol() or atoll() seem more appropriate.
        //        FYI: I made the same mistake ;) [but it's still a bug]
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
        // leczb: Style: no need to add break to the default case.
        break;  
    }
  }
  
  // leczb: You malloc space, store the pointer in pathname and then immediately
  //        overwrite that pointer to argv[optind] or ".", throwing away the
  //        reference to the malloc()'d space (so you won't be able to free()
  //        it) and wasting 1024 bytes from the heap at the same time.
  pathname = (char*) malloc(1024);
  pathname = (argc > optind) ? argv[optind] : ".";
  if (chdir(pathname)) 
    // leczb: You can't assume what went wrong. You have to use strerror().
    fail_miserably("Incorrect directory");
  
  // leczb: You don't seem to use final_status for anything.
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
