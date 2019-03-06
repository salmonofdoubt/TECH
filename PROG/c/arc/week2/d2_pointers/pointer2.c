/* LIST0901.c: Day 9 Listing 9.1 */
/* Demonstrates basic pointer use. */
 
#include <stdio.h>
 
int var = 1;    // a basic var, already initialized 
int *ptr = &var;//a pointer, initilized to addr of var
 
int main(void) {
  
  //ptr = &var;   //here the pointer is initilized
    
  printf("\nDirect access, value of var = %d", var);
  printf("\nAccess by deref (*ptr), var = %d", *ptr);
  
  /* Display the address of var two ways. */
  printf("\n\nThe address (&) of var = %d", &var);
  printf("\nThe address of (ptr) var = %d", ptr);
  return 0;
}