#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_find.h"

int scandir_filter(const struct dirent * name) {
  return (strcmp(name->d_name, ".") != 0 &&
          strcmp(name->d_name, "..") != 0);
}

int name_matching(const char * name, const unsigned char * type,
                  const char * match) {
  if (match == NULL) { return 1; }
  if (*type != DT_DIR) {
    return (!strcmp(name, match));
  } else {
    return 0;
  }
}

int type_matching(const struct dirent * name, const char * type) {
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
  char * subpath;
  char * filename;
  // leczb: This could have been declared as unsigned char, instead of a pointer
  unsigned char * filetype;
  int n;
  static int depth = 0;
  struct dirent ** namelist;

  if (ops->max_depth != NULL) {
    if (*ops->max_depth == -1) {
      printf("%s\n", path);
      exit(EXIT_SUCCESS);
    }
  }
  // leczb: Nice way to call scandir()!
  n = scandir(path, &namelist, scandir_filter, alphasort);
  if (n < 0) {
    perror("scandir");
    return;
  }
  // leczb: I'm not sure about this. When is the -- evaluated. This might be a
  //        bug. Needs testing.
  while (n--) {
    filename = namelist[n]->d_name;
    filetype = &namelist[n]->d_type;
    // leczb: Design comment: this if-nesting can get really deep if you want to
    //        introduce more matchers later.
    if (name_matching(filename, filetype, ops->match) == 1) {
      if (type_matching(namelist[n], ops->type) == 1) {
        printf("%s/%s\n", path, filename);
      }
    }
    if (filetype[0] == DT_DIR) {
      if (ops->max_depth == NULL) {
        subpath = malloc(strlen(path) + strlen(filename) + 2);
        strcpy(subpath, path);
        strcat(subpath, "/");
        strcat(subpath, filename);
        find(subpath, ops);
        // leczb: Niice! Avoided the memory leak by free()ing ;)
        free(subpath);
      }
      if ((ops->max_depth != NULL) && (depth < *ops->max_depth)) {
        depth++;
        subpath = malloc(strlen(path) + strlen(filename) + 2);
        strcpy(subpath, path);
        strcat(subpath, "/");
        strcat(subpath, filename);
        find(subpath, ops);
        free(subpath);
      }
    }
    free(namelist[n]);
  }
  free(namelist);
}
