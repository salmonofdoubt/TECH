/* LIST0401.c: Day 4 Listing 4.1 */
/* Demonstrates unary operator */
/* prefix and postfix modes. */
 
#include <stdio.h>

 
int main(void){
  int i;
  
  int a = 5;
  for (i = 0; i < 5; i++)
    printf("a--: %d\n", a--);
  
  a = 5;     
  for (i = 0; i < 5; i++)
    printf("--a: %d\n", --a);
    
    
/*
  printf("\n%d   %d", a--, --b);
  printf("\n%d   %d", a--, --b);
  printf("\n%d   %d", a--, --b);
  printf("\n%d   %d", a--, --b);
*/  
  return 0;
}