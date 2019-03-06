/* LIST0405.c: Day 4 Listing 4.5 */
/* Demonstrates the evaluation of relational */
/* expressions. */
 
#include <stdio.h>
 
int a;
 
int main(void) {
  a = (5 == 5); /* Evaluates to 1. */
  printf("\na = (5 == 5)\na = %d", a);
  
  a = (5 != 5); /* Evaluates to 0. */
  printf("\na = (5 != 5)\na = %d", a);
  
  a = (12 == 12) + (5 != 1); /* 1 + 1. */
  printf("\na = (12 == 12) + (5 != 1)\na = %d", a);
  return 0;
}