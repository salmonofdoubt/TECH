#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#include "utils.h"
#include "find.h"

/* Scandir filter function for skipping "." and ".." entries */
int skip_dotdirs(const struct dirent *entry) {
  return !(entry->d_type == DT_DIR
           && (   strcmp(entry->d_name, ".") == 0
               || strcmp(entry->d_name, "..") == 0));
}

char apply_filters(const char *path, const struct dirent *dent, predicate_t *filter_chain) {
  predicate_t *filter;
  for (filter = filter_chain; *filter != NULL; filter++) {
    if (!(*filter)(path, dent)) {
      return 0;
    }
    filter_chain++;
  }
  return 1;
}

/* Visit path, printf directory entry filenames matching filter predicate and
 * descend into directories
 * If filter is NULL, all filenames are printed (except for "." and "..")
 */
void find(const char *path, predicate_t *filter_chain, int depth) {
  /* Array for storing pointers to struct dirents
   * Note: we are not malloc()'ing space for it, as scandir() does
   *       that for us.
   */
  struct dirent **dirents;
  /* Number of directory entries returned by scandir */
  int n;
  /* Generic loop variable */
  int i;

  /* If the maximum recursion depth is set, check if we have hit that limit */
  if (opt_depth >= 0 && (depth > opt_depth)) {
    return;
  }

  /* Request reading directory entries from path, sorted in alphabetical order,
   * filtering out "." and ".." entries
   */
  n = scandir(path, &dirents, skip_dotdirs, alphasort);

  if (n < 0) {
    fprintf(stderr, "error opening '%s': %s\n", path, strerror(errno));
  } else {
    for (i = 0; i < n; i++) {
      /* Printing */
      if (filter_chain == NULL /* No filter chain was supplied */
          || apply_filters(path, dirents[i], filter_chain)) {
        printf("%s/%s\n", path, dirents[i]->d_name);
      }

      /* Visiting directories below this path */
      if (dirents[i]->d_type == DT_DIR) {
        char *new_path = path_append(path, dirents[i]->d_name);
        /* Recursion */
        find(new_path, filter_chain, depth + 1);
        /* Free up the memory we malloc()'d for the path */
        free(new_path);
      }
      /* Free up the dirent element scandir() malloc()'d for us */
      free(dirents[i]);
    }
    /* Free up the dirents pointer array scandir() malloc()'d for us */
    free(dirents);
  }
}
