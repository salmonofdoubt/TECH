#include <stdio.h>
#include <stdlib.h>
 
int small[10];
int new[10];
int i;

 
int main(void) {  
  //first array
  for (i = 0; i < 10; i++)
    small[i] = i;
  
  for (i = 0; i < 10; i++) {
    printf("\nsmall[%d] =", i);
    printf("%d", small[i]);
  }
  
  // second array
  for (i = 0; i < 10; i++)
    new[i] = small[i] + 10;
  
  for (i = 0; i < 10; i++) {
    printf("\nnew[%d] =", i);
    printf("%d", new[i]);
  }
  return 0;
}