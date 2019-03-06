/* LIST1002.c: Day 10 Listing 10.2 */
/* Demonstrates printing extended ASCII */
/* characters. MS-DOS Application Only */
 
#include <stdio.h>
/* Must be unsigned for extended ASCII. */
 
int main(void) {
 
  unsigned char x = 'a';
  for (x = 180; x < 204; x++) {
    printf("\nASCII code %d is character %c", x, x);
  }
  
  char *message = "Great Ceasar's Ghost!";
  printf("\nMESSAGE:\n %s", message);
  
  return 0;
}