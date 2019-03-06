/* LIST0504.c: Day 5 Listing 5.4 */
/* Demonstrates using multiple return */
/* statements in a function. */
 
#include <stdio.h>
 
int x, y, z;
int larger_of(int a, int b);
 
int main(void) {
  
  puts("Enter two different integer values: ");
  scanf("%d%d", &x, &y);
  
  z = larger_of(x, y);                      //z is whatever is returned from larger_of
  printf("\nThe larger value is %d.", z);
  return 0;
}
 
int larger_of(int a, int b) {
  if (a > b)
    return a;
      else
        return b;
}