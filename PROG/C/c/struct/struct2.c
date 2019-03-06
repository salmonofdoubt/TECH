// Struct: used to package related data together.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct foo {                          // declare / name it. ususally in header
	  int x;
	  int array[100];
  } any;                              // make it a var
  
int main(int argc, char *argv[]) {
                                        
  any.x = 54;                         // init it
  any.array[3] = 9;
  																		// use it
  printf("element 'x':        \n %d\n", any.x);
  printf("element 'array[9]': \n %d\n", any.array[3]);
  
  exit(EXIT_SUCCESS);
}

