/* LIST0804.c: Day 8 Listing 8.4 */
/* Demonstrates the sizeof() operator.*/
 
#include <stdio.h>
 
/* Declare several 100 element arrays. */
 
int intarray[1];
float floatarray[1];
double doublearray[1];
 
int main(void) {
  /* Display the sizes of numeric data types. */
  
  printf("\n\nSize of int = %d bytes",
          sizeof(int));  
  printf("\nSize of short = %d bytes",
          sizeof(short));
  printf("\nSize of long = %d bytes",
          sizeof(long));
  printf("\nSize of float = %d bytes",
          sizeof(float));
  printf("\nSize of double = %d bytes",
          sizeof(double));
  
  /* Display the sizes of the three arrays. */
  
  printf("\n\nSize of intarray = %d bytes",
          sizeof(intarray));
  printf("\nSize of floatarray = %d bytes",
          sizeof(floatarray));
  printf("\nSize of doublearray = %d bytes",
          sizeof(doublearray));
  
  return 0;
}