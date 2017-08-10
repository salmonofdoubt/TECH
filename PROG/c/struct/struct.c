// Struct: a variable, used to package related data.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  
  struct coords {
	  int x;
	  int y;
  } a;
  
  a.x = 34;
  a.y = 23;
	
  
  printf("coordinates are (%d,%d)\n", a.x, a.y);

  exit(EXIT_SUCCESS);
}
