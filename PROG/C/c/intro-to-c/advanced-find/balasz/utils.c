#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/* Append an element to a path
 * Returns a new string with path_prefix + "/" + path
 */
char * path_append(const char *path_prefix, const char *path) {
  /* The length of the buffer required for storing the new path:
   *    the length of path_prefix
   *  + 1 (for the "/" separator)
   *  + the length of path
   *  + 1 (for the terminating zero)
   */
  size_t new_path_length = strlen(path_prefix) + strlen(path) + 2;
  char *new_path = (char *) malloc(new_path_length);
  /* Compose the path of the directory we want to visit */
  snprintf(new_path, new_path_length,
           "%s/%s", path_prefix, path);
  return new_path;
}
