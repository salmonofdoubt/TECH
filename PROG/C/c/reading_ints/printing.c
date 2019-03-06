#include <stdio.h>

void print_array(int* array, int length) {
  int i;
  printf("%s\n", "Printing array:");
  for(i = 0; i < length; i++) {
    printf("Position %d: %d\n", i, array[i]);
  }
}

void print_average(int* array, int length) {
  int i, total;
  total = 0;
  for(i = 0; i < length; i++) {
    total += array[i];
  }
  printf("Average: %.2f\n", total / (float) length);
}