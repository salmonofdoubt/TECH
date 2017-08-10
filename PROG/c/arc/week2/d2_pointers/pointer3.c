/* LIST0902.c: Day 9 Listing 9.2 */
/* Demonstrates the relationship between */
/* addresses and elements of arrays of */
/* different data types. */
 
#include <stdio.h>
 
/* Declare three arrays and a counter variable. */
 
short s[10], x;
float f[10];
double d[10];
 
int main(void) {
  /* Print the table heading. */
  
  printf("\n\nPrinting Start Bytes (Address blocks)\n\n");
  printf("\tShort\t\tFloat\t\tDouble");
  printf("\n================================");
  printf("====================");  
 
  /* Print the addresses of each array element. */
 
  for (x = 0; x < 10; x++)
    printf("\ne %d:\t%d\t\t%d\t\t%d", x,
           &s[x], &f[x], &d[x]);
        
  printf("\n================================");
  printf("====================");
  return 0;
}
