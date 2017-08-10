#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  if (*(int *)a == *(int *)b) {
    return 0;
  }
  if (*(int *)a < *(int *)b) {
    return 1;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int array[10] = {5, 2, 7, 3, 4, 1, 9, 8, 0, 6};
  int i;

  qsort(array, 10, sizeof(int), compare);

  for (i = 0; i < 10; i++) {
    printf("%d: %d\n", i, array[i]);
  }
}
