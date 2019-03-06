#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define CHUNKSIZE 1000

int compare_filenames(const void *a, const void *b) {
  return strncmp(*(char **)a, *(char **)b, 256);
}

void print_sorted(const char *filenames, const unsigned int entries) {
  const char **array;
  int i;

  array = (const char **) malloc(entries * sizeof(char *));
  for (i = 0; i < entries; i++) {
    array[i] = filenames + i * 256;
  }

  qsort((void *)array, entries, sizeof(char *), compare_filenames);
  for (i = 0; i < entries; i++) {
    printf("%s\n", array[i]);
  }

  free(array);
}

int main(int argc, char *argv[]) {
  DIR *dirp;
  struct dirent *dirent;

  char *filenames;
  unsigned int buffsize = CHUNKSIZE;
  unsigned int entries = 0;

  unsigned int i = 0;

  if (argc < 2) {
    printf("Usage: %s <dir>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  dirp = opendir(argv[1]);
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  filenames = (char *) malloc(buffsize * 256);

  while ((dirent = readdir(dirp)) != NULL) {
    strncpy(filenames + 256 * entries, dirent->d_name, 256);
    entries++;
    if (entries == buffsize) {
      buffsize += CHUNKSIZE;
      filenames = (char *) realloc(filenames, buffsize * 256);
    }
  }

  print_sorted(filenames, entries);

  exit(EXIT_SUCCESS);
}
