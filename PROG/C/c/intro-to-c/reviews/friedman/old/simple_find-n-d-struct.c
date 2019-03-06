#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LG_BUFSIZE 1048576 /* 1MB */
#define SM_BUFSIZE 256

//typedef int (*scandir_filter)(const struct dirent *, const char *);

struct operations {
  char * match;
  int * max_depth;
};

int scandir_filter(const struct dirent * filename) {
  if (strcmp(filename->d_name, ".") != 0 &&
      strcmp(filename->d_name, "..") != 0) { return 1; }
}

int name_matching(const struct dirent * name,
                  const char * match) {
  if (match == NULL) { return 1; }
  if (name->d_type & DT_REG) {
    return (!strcmp(name->d_name, match));
  } else {
    return 0;
  }
}

void find(const char * path, const struct operations * ops) {
  //printf("%p %d %s\n", ops, *ops->max_depth, ops->match);
  char * subpath;
  char * filename;
  int n;
  static int depth = 0;
  struct dirent ** namelist;

  if (*ops->max_depth == -1) {
    printf("%s\n", path);
    exit(EXIT_SUCCESS);
  }
  n = scandir(path, &namelist, scandir_filter, alphasort);
  if (n < 0) {
    perror("scandir");
    return;
  }
  while (n--) {
    filename = namelist[n]->d_name;
    if (name_matching(namelist[n], ops->match) == 1) {
      printf("%s/%s\n", path, filename);
    }
    if ((namelist[n]->d_type & DT_DIR) && (ops->max_depth != NULL)) {
      if (depth < *ops->max_depth) {
        depth++;
        subpath = malloc(LG_BUFSIZE);
        strcpy(subpath, path);
        strcat(subpath, "/");
        strcat(subpath, namelist[n]->d_name);
        find(subpath, ops);
        free(subpath);
      }
    }
    free(namelist[n]);
  }
  free(namelist);
}

int main (int argc, char * argv[]) {
  int opt;
  int max_depth;
  char * path;
  char * match;
  struct operations * ops;

  ops = (struct operations *)malloc(sizeof(struct operations));
  ops->match = NULL;
  ops->max_depth = NULL;

  path = malloc(sizeof(char)*LG_BUFSIZE);
  while ((opt = getopt(argc, argv, "d:n:")) != -1) {
    switch (opt) {
      case 'd':
        max_depth = atoi(optarg);
        max_depth--;
        ops->max_depth = &max_depth;
        break;
      case 'n':
        ops->match = (char *)malloc(sizeof(char)*SM_BUFSIZE);
        strcpy(ops->match, optarg);
        break;
      default:
        printf("Usage: %s [-d <max depth>] [-n <filename match>]\n",
            argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  if (optind == argc) {
    path = ".";
  } else {
    path = argv[argc - 1];
  }
  //if (chdir(path) != 0) { perror("Could not chdir"); }
  find(path, ops);
  exit(EXIT_SUCCESS);
}
