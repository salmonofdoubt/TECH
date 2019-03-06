/* EXER0202.c: Day 2 Exercise 2.2 */

#include <stdio.h>
  
void display_line(void);        //fct PROTOTYPE

int main(void) {
  display_line();
  printf("\n C User Guide\n");
  display_line();
  return 0;
}

/* Print asterisk line. */
void display_line(void) {
  int counter;
  for (counter = 0; counter < 21; counter++)
    printf("*");
}