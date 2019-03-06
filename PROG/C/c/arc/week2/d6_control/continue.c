/* LIST1302.c: Day 13 Listing 13.2 */
/* Demonstrates the continue statement. */
 
#include <stdio.h>
 
int main(void) {
  
  char buffer[81];
  int i;
  
  puts("Enter a line of text:");
  gets(buffer);
  
  for (i = 0; buffer[i] !='\0'; i++) {
    if (buffer[i] == 'a' || buffer[i] == 'e' ||
      buffer[i] == 'i'
      || buffer[i] == 'o' || buffer[i] == 'u')
      continue;	/* Continue does NOT end a loop, it just skips to next iteration */
      
    /* So if [i] not a vowel, display it.*/
    putchar(buffer[i]);
  }
  return 0;
}