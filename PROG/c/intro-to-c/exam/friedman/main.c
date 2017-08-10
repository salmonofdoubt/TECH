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

  ops = (struct operations *)malloc(sizeof(struct operations));
  ops->match = NULL;
  ops->max_depth = NULL;
  ops->type = NULL;

  while ((opt = getopt(argc, argv, "n:t:d:")) != -1) {
    switch (opt) {
      case 'd':
        max_depth = atoi(optarg);
        max_depth--;
        ops->max_depth = &max_depth;
        break;
      case 'n':
        ops->match = (char *)malloc(sizeof(optarg));
        strcpy(ops->match, optarg);
        break;
      case 't':
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
    path = (char *)malloc(2);
    strcpy(path, ".");
  } else {
    path = (char *)malloc(sizeof(argv[argc - 1]) + 1);
    strcpy(path, argv[argc - 1]);
  }
  find(path, ops);
  exit(EXIT_SUCCESS);
}
