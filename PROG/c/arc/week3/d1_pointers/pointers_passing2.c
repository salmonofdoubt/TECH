/* LIST1506.c: Day 15 Listing 15.6 */
/* Passing an array of pointers to a function. */
 
#include <stdio.h>

void print_fct(char *p[], int n);
 
int main(void) {

  char *message[8] = {"Four", "score", "and"};
  print_fct(message, 8);

  return 0;
}
 
void print_fct(char *p[], int n) {
  int i;

  for (i = 0; i < n; i++)
    printf("%s ", p[i]);
}