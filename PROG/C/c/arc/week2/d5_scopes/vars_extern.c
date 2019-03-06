/* LIST1201.c: Day 12 Listing 12.1 */
/* Illustrates variable scope. */
 
#include <stdio.h>
 
int x = 999;

void print_value(int x);
 
int main(void) {
	extern int x;				/*when using global vars, redclare for readability*/
	
  printf("%d\n", x);
  print_value(x);
  return 0;
}
 
void print_value(x) {
  printf("%d\n", x);
}