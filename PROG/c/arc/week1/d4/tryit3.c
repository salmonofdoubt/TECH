/* LIST0401.c: Day 4 Listing 4.1 */
/* Demonstrates unary operator */
/* prefix and postfix modes. */
 
#include <stdio.h>
 
int x, y = 0;
 
int main(void){
  /* Set a and b both equal to 5. */
  printf("Enter value of x: ");
  scanf("%d", &x);
  if (x >= 1 && x <= 20)
  {
    y = x;
    printf("y has been changed to %d.", y);
  }
  else 
  {
    printf("y has not been changed (%d).", y);
  }
  // same calc using conditional operator:
  // y = ((x >= 1) && (x <= 20)) ? x : y;
  return 0;
}