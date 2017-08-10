/* LIST1006.c: Day 10 Listing 10.6 */
/* Demonstrates using the gets() return value. */
 
#include <stdio.h>
 
/* Declare a character array to hold input, and */
/* a pointer. */
 
char input[81], *ptr;
 
int main(void) {
  /* Display instructions. */
  
  puts("Enter text a line at a time,");
  
  //Loop as long as input is not a blank line.  
  //* derefs to 1st char of input, which is compared to NULL
  while (*(ptr = gets(input)) != '\0')
    printf("You entered %s\n", input);
    
  puts("Thank you and good-bye");
  return 0;

  char letter = '$';
  char array[18] = "Pointers are fun!";
  char *string = 'Pointers are fun!';
  
  char *p_str;
  p_str = malloc(81);
  gets(p_str);
  
  
  
  
}