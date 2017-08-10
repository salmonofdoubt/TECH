/* EXER1209.c: Day 12 Exercise 12.9 */

#include <stdio.h>

void print_letter2(void);

int ctr;
char letter1 = 'X';
char letter2 = '=';

int main(void) {
  for(ctr = 0; ctr < 10; ctr++) {
     printf("%c", letter1);
     print_letter2();
  }   
  return 0;
}

void print_letter2(void) {
	int i;
  for(i = 0; i < 2; i++)
    printf("%c", letter2);
}