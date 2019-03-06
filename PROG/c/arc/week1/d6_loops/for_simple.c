#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  int i, j;
  int a[] = {0,1,2,3,4};
  int b[5];
  
  for (i = 0, j = 5; i < 5; i++, j--)
    b[j] = a[i];
  
  printf("a:\n");
  for (i = 0; i < 5; i++)
    printf("%d, ", a[i]);
  printf("\n\n");
  
  printf("b:\n");
  for (i = 0; i < 5; i++)
    printf("%d, ", b[i]);
  
    
  return 0;
  //exit(EXIT_SUCCESS);
}

