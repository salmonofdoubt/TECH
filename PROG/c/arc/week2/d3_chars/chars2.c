/* LIST1004.c: Day 10 Listing 10.4 */
/* Demonstrates displaying strings with puts(). */
 
#include <stdio.h>
#include <stdlib.h>
 
char *str;
 
int main(void) {
  
  //str = malloc(100 * sizeof(char));
  printf("Enter a string: \n");
  scanf("%s", str);
  printf("%s", str);
  return 0;
}

