/*
A direct implementation of getline EXAMPLE (see man 3 getline)
Using argv to pass searchstring and filename, that's it. 

Does not compile on Mac. OK on Linux.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  int i;
  FILE *file;
  char *line = NULL;
  char *searchstring;
  size_t length;

  if (argc < 3) {
    printf("Usage: %s <searchstring> <filename> [filename...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  searchstring = argv[1];

  for (i = 2; i < argc; i++) {
    if ((file = fopen(argv[i], "r")) == NULL) {
      perror("Opening file failed");
      exit(EXIT_FAILURE);
    }
    
/*
strstr()  function  finds  the first occurrence of substring needle in string haystack
*/
    while (getline(&line, &length, file) != -1) {
      if (strstr(line, searchstring) != NULL) {
        printf("%s", line);
      }
      free(line);                     //see man 3 getline
      line = NULL;
    }

    if (fclose(file) != 0) {
      perror("Closing file failed");
      exit(EXIT_FAILURE);
    }
  }

  exit(EXIT_SUCCESS);
}
