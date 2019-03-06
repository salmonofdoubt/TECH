#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

  char array[30] = {0,0,0};  
  int *ptr;
  int i;
  
  ptr = (int *) malloc(1 * sizeof(int));
	
	if (ptr == NULL) {
    printf("memory could not be allocated");
  }
  /*
  - malloc looks for 3 times the sizeof int (3* 4bytes) on heap
	- if ok, it sticks the address of the reserved block into ptr
	- so ptr now contains an address, which is able to hold the requested space
  */

  else
    for (i=0; i < 3; i++){
      printf("enter the %dth element:", i);
      scanf("%s", &array[i+1]);
    }
    for (i=0; i < 3; i++)
      printf("%s", &array[i]);
  
  free(ptr);
  ptr = NULL; 
	return 0;

}
