/* EXER1205.c: Day 12 Exercise 12.5 */
/* Using a global variable */

#include <stdio.h>

int var = 99;

void print_func(void);

int main(void) {
  int var = 77;
  printf("MAIN: local var = 77,  global var = 99:");
  printf("\nThe value of var is %d", var);
  print_func();
  return 0;
}  

void print_func(void) {
  printf("\nFUNC: Only global var available, global var = 99:");
  printf("\nThe value of var is %d", var);
}