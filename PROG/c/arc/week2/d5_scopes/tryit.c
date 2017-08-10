/* LIST1202.c: Day 12 Listing 12.2 */
/* Illustrates variable scope. */
 
#include <stdio.h>
 
void print_value(int x);
 
int main(void) {
  int x = 999;
  
  printf("%d\n", x);
  print_value(x);
  return 0;
}
 
void print_value(int x) {
  printf("%d\n", x);
}
