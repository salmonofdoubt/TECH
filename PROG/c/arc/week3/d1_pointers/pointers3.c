/* LIST1503.c: Day 15 Listing 15.3 */
/* Demonstrates pointer arithmetic with pointers */
/* to multidimensional arrays. */
 
#include <stdio.h>
 
int multi[2][4] = {{1,2}, {3,4}};
 
int main(void) {
  printf("\nThe value of (multi) = %u", **multi);
  printf("\nThe value of (multi + 1) = %u", **(multi + 1));
  printf("\nThe address of multi[1] = %d", multi[1]);


	/* interchangable */
/*char message[] = "This is the message.";*/
	char *message = "This is the message.";
	
	printf("\nmessage is = %s", message);

	return 0;
}