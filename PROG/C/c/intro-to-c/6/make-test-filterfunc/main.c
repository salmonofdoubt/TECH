#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "filter.h"

int odd(const void *input) {
 return *(int *)input & 1;
}

int main(int argc, char *argv[]) {
  int array[10] = {5, 2, 7, 3, 4, 1, 9, 8, 0, 6};
  int i;
  int *result;
  size_t result_size;

  filter(array,
         sizeof(int),
         10,
         (void *)&result,
         &result_size,
         odd);

  printf("Original:\n");
  for (i = 0; i < 10; i++) {
    printf("%d: %d\n", i, array[i]);
  }

  printf("Filtered:\n");
  for (i = 0; i < result_size; i++) {
    printf("%d: %d\n", i, result[i]);
  }
}
