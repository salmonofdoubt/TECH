/* LIST0201.c: Day 2 Listing 2.1 
 * MULTIPLY.C: Program to calculate the product
 * of two numbers. */

#include <stdio.h>

int a, b, c;
int product(int x, int y);        //function PROTOTYPE, always before the actual function



int main(void) {
  /* Input the first number. */
  printf("Enter a number between 1 and 100: ");
  scanf("%d", &a);
  
  /* Input the second number. */
  printf("Enter another number"
         " between 1 and 100: ");
  scanf("%d", &b);
  
  /* Calculate and display the product. */
  c = product(a, b);
  printf("\n%d times %d = %d", a, b, c);
  return 0;
}

/* Function returns the product of its two
 * arguments. */
int product(int x, int y) {     //function DEFINITION, actual content 
  return (x * y);
}