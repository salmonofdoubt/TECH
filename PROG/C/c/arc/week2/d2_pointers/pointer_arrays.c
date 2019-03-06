/* LIST0903.c: Day 9 Listing 9.3 */
/* Demonstrates using pointer arithmetic to */
/* access array elements with pointer notation. */
 
#include <stdio.h>
#define MAX 10
 
int int_arr[MAX] = { 0,1,2,3,4,5,6,7,8,9};
float float_arr[MAX] = {.0,.1,.2,.3,.4,.5,.6,.7,.8,.9};
int i;
 
// Declare a pointers
int *p_int_arr;
float *p_float_arr;

int main(void) {
// Initialize the pointers
// Arrays already are pointers, so dont use &i_array
  p_int_arr = int_arr;  
  p_float_arr = float_arr;
  
//Print the array values by using the pointers.
  for (i = 0; i < MAX; i++)
    printf("\n%d\t%f", *p_int_arr++, *p_float_arr++);
  return 0;
}