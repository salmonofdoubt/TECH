#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "utils.h"
#include "predicates.h"

/* Filter function that returns
 *  1 if the owner of the given file matches opt_uid
 *  0 otherwise
 */
int pred_uid(const char *path, const struct dirent *entry) {
  /* Result from stat() */
  struct stat s;
  /* Full filename */
  char *filename = path_append(path, entry->d_name);
  if (stat(filename, &s) < 0) {
    fprintf(stderr, "error during stat('%s'): %s\n", filename, strerror(errno));
    return 0;
  }
  free(filename);
  return s.st_uid == opt_uid;
}


/* Filter function that returns
 *  1 if the group of the given file matches opt_gid
 *  0 otherwise
 */
int pred_gid(const char *path, const struct dirent *entry) {
  /* Result from stat() */
  struct stat s;
  /* Full filename */
  char *filename = path_append(path, entry->d_name);
  if (stat(filename, &s) < 0) {
    fprintf(stderr, "error during stat('%s'): %s\n", filename, strerror(errno));
    return 0;
  }
  free(filename);
  return s.st_gid == opt_gid;
}


/* Filter function that returns
 *  1 if the size of the given file is at larger than or equals to opt_min_size
 *  0 otherwise
 */
int pred_min_size(const char *path, const struct dirent *entry) {
  /* Result from stat() */
  struct stat s;
  /* Full filename */
  char *filename = path_append(path, entry->d_name);
  if (stat(filename, &s) < 0) {
    fprintf(stderr, "error during stat('%s'): %s\n", filename, strerror(errno));
    return 0;
  }
  free(filename);
  return s.st_size >= opt_min_size;
}

       
/* Filter function that returns
 *  1 if the name of the given file matches opt_name
 *  0 otherwise
 */
int pred_name(const char *path, const struct dirent *entry) {
  return strncmp(entry->d_name, opt_name, 256) == 0;
}


/* Filter function that returns
 *  1 if the type of the given file matches opt_type
 *  0 otherwise
 */
int pred_type(const char *path, const struct dirent *entry) {
  return entry->d_type == opt_type;
}
