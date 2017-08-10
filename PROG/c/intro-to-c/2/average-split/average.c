#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 1024

#include "printing.h"

int main(int argc, char *argv[]) {
  int *data;                  // Buffer pointer
  int i = 0;                  // The index of the next empty slot in the buffer
  int bufsize = CHUNKSIZE;    // The size of the buffer (number of int slots)

  if ((data = (int *) malloc(sizeof(int) * bufsize)) == NULL) {
    exit(EXIT_FAILURE);
  }

  while (scanf("%i", &data[i]) != EOF) {
    i++;
    if (i == bufsize) {
      bufsize += CHUNKSIZE;
      printf("Reallocating with %d number of ints\n", bufsize);
      if ((data = (int *) realloc(data, sizeof(int) * bufsize)) == NULL) {
        exit(EXIT_FAILURE);
      }
    }
  }

  print_array(data, i);
  print_average(data, i);

  exit(EXIT_SUCCESS);
}
