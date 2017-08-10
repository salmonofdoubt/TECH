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
  char * type;
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

int type_matching(const struct dirent * name,
                  const char * type) {
  if (type == NULL) { return 1; }
  switch (type[0]) {
    case 'l':
      return (name->d_type == DT_LNK);
      break;
    case 'd':
      return (name->d_type == DT_DIR);
      break;
    case 'f':
      return (name->d_type == DT_REG);
      break;
    case 'c':
      return (name->d_type == DT_CHR);
      break;
    case 'b':
      return (name->d_type == DT_BLK);
      break;
    case 's':
      return (name->d_type == DT_SOCK);
      break;
    default:
      return 1;
  }
}

void find(const char * path, const struct operations * ops) {
  //printf("%p %d %s\n", ops, *ops->max_depth, ops->match);
  char * subpath;
  char * filename;
  int n;
  static int depth = 0;
  struct dirent ** namelist;

  if (ops->max_depth != NULL) {
    if (*ops->max_depth == -1) {
      printf("%s\n", path);
      exit(EXIT_SUCCESS);
    }
  }
  n = scandir(path, &namelist, scandir_filter, alphasort);
  if (n < 0) {
    perror("scandir");
    return;
  }
  while (n--) {
    filename = namelist[n]->d_name;
    if (name_matching(namelist[n], ops->match) == 1) {
      if (type_matching(namelist[n], ops->type) == 1) {
        printf("%s/%s\n", path, filename);
      }
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
  ops->type = NULL;

  path = malloc(sizeof(char)*LG_BUFSIZE);
  while ((opt = getopt(argc, argv, "n:t:d:")) != -1) {
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
    path = ".";
  } else {
    path = argv[argc - 1];
  }
  //if (chdir(path) != 0) { perror("Could not chdir"); }
  find(path, ops);
  exit(EXIT_SUCCESS);
}
