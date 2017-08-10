#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "simple_find.h"

int main (int argc, char * argv[]) {
  int opt;
  int max_depth;
  char * path;
  struct operations * ops;

  // leczb: You could have declared ops as struct operations.
  //        Then you don't have to malloc() and free().
  ops = (struct operations *)malloc(sizeof(struct operations));
  ops->match = NULL;
  ops->max_depth = NULL;
  ops->type = NULL;

  while ((opt = getopt(argc, argv, "n:t:d:")) != -1) {
    switch (opt) {
      case 'd':
        max_depth = atoi(optarg);
        // leczb: Not sure why you need to decrement it, but
        //        looks suspicious :)
        max_depth--;
        ops->max_depth = &max_depth;
        break;
      case 'n':
        // leczb: This is not gonna work. optarg is pointer.
        //        Its size is going to be 4 or 8. So most
        //        probably, this malloc() is not going to
        //        allocate enough memory for the string.
        //        What you need here is malloc(strlen(optar))
        ops->match = (char *)malloc(sizeof(optarg));
        // leczb: Actually, you don't *have* to copy the optarg.
        //        Just save the pointer:
        //          ops->match = optarg;
        strcpy(ops->match, optarg);
        break;
      case 't':
        // leczb: Why "+ 10"? BTW: sizeof(char) is 1, by definition.
        ops->type = (char *)malloc(sizeof(char) + 10);
        strcpy(ops->type, optarg);
        break;
      default:
        printf("Usage: %s [-n <filename match>] ", argv[0]);
        printf("[-t <filetype>] [-d <max depth>]\n");
        exit(EXIT_FAILURE);
    }
  }
  if (optind == argc) {
    // leczb: The "." string constant is already stored in the data segment for
    //        you. There's no need to copy it. So these two lines could be collapsed
    //        into:
    //          path = ".";
    path = (char *)malloc(2);
    strcpy(path, ".");
  } else {
    // leczb: ...and this could have been
    //          path = argv[argc - 1];
    path = (char *)malloc(sizeof(argv[argc - 1]) + 1);
    strcpy(path, argv[argc - 1]);
  }
  // leczb: Nicely done!
  find(path, ops);
  exit(EXIT_SUCCESS);
}
