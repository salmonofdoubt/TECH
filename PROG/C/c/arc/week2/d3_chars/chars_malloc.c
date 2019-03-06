/* LIST1003.c: Day 10 Listing 10.3 */
/* Demonstrates the use of malloc() to allocate */
/* storage space for string data. */
 
#include <stdio.h>
#include <stdlib.h>
 

int main(void) {  
  
  char *ptr, *p;
  int i;

  //Asking to allocate ptr a block of 35 bytes.
  ptr = malloc(35 * sizeof(char));
  
  //Test for success. 
  if (ptr == NULL) {
    puts("Memory allocation error.");
  //The exit() library function would terminate program. 
    exit(1);
  }
  
  //p is assigned the same address value as ptr. 
  //ptr to remain pointed at the start of the string.
  p = ptr;
  
 //use this new pointer to place values into the allocated memory
  for (i = 65; i < 91; i++){
    *p++ = i;
    puts(ptr);    //putString just testing how ptr changes then..
  }
    
  //Add the terminating null character.
  //*p = '\0';
  
  // Display the string on the screen.
  puts(ptr);      //putString
  return 0;
}