#include <stdio.h>
#include <stdlib.h>

void print_array(int *data, int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d: %d\n", i, data[i]);
  }
}

void print_average(int *data, int n) {
  int i = 0;
  double sum = 0;
  for (i = 0; i < n; i++) {
    sum += data[i];
  }
  printf("Average: %f\n", sum / n);
}
