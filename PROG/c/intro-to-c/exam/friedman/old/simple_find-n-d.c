#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LG_BUFSIZE 1048576 /* 1MB */
#define SM_BUFSIZE 256

//typedef int (*scandir_filter)(const struct dirent *, const char *);

int scandir_filter(const struct dirent * filename) {
  if (strcmp(filename->d_name, ".") != 0 &&
      strcmp(filename->d_name, "..") != 0) { return 1; }
}

void find(const char * path, const char * match, const int max_depth) {
  char * subpath;
  int n;
  static int depth = 0;
  struct dirent ** namelist;

  n = scandir(path, &namelist, scandir_filter, alphasort);
  if (n < 0) {
    perror("scandir");
    return;
  }
  while (n--) {
    /* Handle -n */
    if (strcmp(match, "")) {
      if (namelist[n]->d_type & DT_REG) {
        if (!strcmp(namelist[n]->d_name, match)) {
          printf("%s/%s\n", path, namelist[n]->d_name);
        }
      } /* End of -n handling */
    } else {
      printf("%s/%s\n", path, namelist[n]->d_name);
    }
    /* Traverse into subdirs */
    if ((namelist[n]->d_type & DT_DIR) &&
        (depth < max_depth)) {
      depth++;
      subpath = malloc(LG_BUFSIZE);
      strcpy(subpath, path);
      strcat(subpath, "/");
      strcat(subpath, namelist[n]->d_name);
      find(subpath, match, max_depth);
      free(subpath);
    } /* End subdir traversal handling */
    free(namelist[n]);
  }
  free(namelist);
}

int main (int argc, char * argv[]) {
  int opt;
  int max_depth;
  char * path;
  char * match;

  path = malloc(sizeof(char)*LG_BUFSIZE);
  match = malloc(sizeof(char)*SM_BUFSIZE);
  strcpy(match, "");
  while ((opt = getopt(argc, argv, "d:n:")) != -1) {
    switch (opt) {
      case 'd':
        max_depth = atoi(optarg);
        break;
      case 'n':
        match = optarg;
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
  find(path, match, max_depth);
  exit(EXIT_SUCCESS);
}
