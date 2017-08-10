/* LIST1301.c: Day 13 Listing 13.1 */
/* Demonstrates the break statement. */
 
#include <stdio.h>
 
char s[] = "This is a test string. It contains two sentences.";
 
int main(void) {
  int count;
  
  printf("\nOriginal string: %s", s);
  
  for (count = 0; s[count] != '\0'; count++)
    if (s[count] == '.') {
      s[count+1] = '\0';
      break;	/* break ends a loop */
    }
    
  printf("\nModified string: %s", s);
  return 0;
}