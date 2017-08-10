/* LIST0905.c: Day 9 Listing 9.5 */
/* Passing an array to a function. */
/* Alternative way. */
 
#include <stdio.h>
#include <limits.h>
#define MAX 5
 
int array[MAX + 1], i;
int largest(int x[]);
 
int main(void) {
  /* Input MAX values from the keyboard. */
  
  for (i = 0; i < MAX; i++) {
    printf("Enter an integer value: ");
    scanf("%d", &array[i]);
    
    if (array[i] == 0)
      i = MAX;      /* Will exit for loop. */
  }
  array[MAX] = 0;
  
  /* Call the function and display the return */
  /* value. */
  
  printf("\n\nLargest value = %d", largest(array));
  return 0;
}
 
/* Function largest() returns the largest value */
/* in an integer array. */
 
int largest(int x[]) {
  int i, biggest = INT_MIN;
  
  for (i = 0; x[i] !=0; i++) {
    if (x[i] > biggest)
      biggest = x[i];
  }
  return biggest;
}