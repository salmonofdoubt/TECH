// Read integers from stdin, print them
// when you get to the end and print their average as well.
// Hints = scanf() is an inverse of printf
// EOF is Ctrl-D
// use malloc and realloc

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "printing.h"

int main(int argc, char *argv[]) {
  int   array_size, current_integer, i, total;
  array_size = i = total = 0;
  int*  array = NULL;
  while (scanf("%d", &current_integer) != EOF) {
    // realloc returns a void pointer, best to cast it 
    array = (int*) realloc(array, sizeof(int) * (array_size + 1));
    array[array_size++] = current_integer;
  }
  
  print_array(array, array_size);
  print_average(array, array_size);
  
  // A nice example of an overflow
  int a = INT_MAX;
  a++;
  if (a == INT_MIN) printf("%s", "yes\n");
  else printf("%s", "no\n");

  unsigned int b = UINT_MAX;
  printf("UINT_MAX plus 1: %d\n", ++b);

}
