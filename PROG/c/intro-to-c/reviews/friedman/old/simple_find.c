#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 4096

//typedef int (*scandir_filter)(const struct dirent *, const char *);

int scandir_filter(const struct dirent * filename) {
  if (strcmp(filename->d_name, ".") != 0 &&
      strcmp(filename->d_name, "..") != 0) { return 1; }
}

void traverse_dir(const char *dirp, const char * match) {
  char * subpath;
  int n;
  struct dirent ** namelist;

  n = scandir(dirp, &namelist, scandir_filter, alphasort);
  if (n < 0) {
    perror("scandir");
    return;
  }
  while (n--) {
    if (strcmp(match, "")) {
      if (namelist[n]->d_type != 4) {
        if (!strcmp(namelist[n]->d_name, match)) {
          printf("%s/%s\n", dirp, namelist[n]->d_name);
        }
      }
    } else {
      printf("%s/%s\n", dirp, namelist[n]->d_name);
    }
    if (namelist[n]->d_type == 4) {
      subpath = malloc(BUFSIZE);
      strcpy(subpath, dirp);
      strcat(subpath, "/");
      strcat(subpath, namelist[n]->d_name);
      traverse_dir(subpath, match);
      free(subpath);
    }
    free(namelist[n]);
  }
  free(namelist);
}

int main (int argc, char * argv[]) {
  int opt, n;
  int i = 0;
  char * path;
  char * match;

  path = malloc(sizeof(char)*BUFSIZE);
  match = malloc(sizeof(char)*BUFSIZE);
  strcpy(match, "");
  while ((opt = getopt(argc, argv, "n:")) != -1) {
    switch (opt) {
      case 'n':
        match = optarg;
        break;
      default:
        fprintf(stderr, "Usage: %s [-n <filename match>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  if (optind == argc) {
    path = ".";
  } else {
    path = argv[argc - 1];
  }
  //if (chdir(path) != 0) { perror("Could not chdir"); }
  traverse_dir(path, match);
  exit(EXIT_SUCCESS);
}
