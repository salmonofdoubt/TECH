/* LIST1305.c: Day 13 Listing 13.5 */
/* Demonstrates the switch statement. */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int reply;
	puts("Enter a number between 1 and 5:");
	scanf("%d", &reply);

  switch(reply) {
    case 1:		/* in case 'reply' becomes 1 */
      puts("You entered 1.");
      break;	/* breaks and jumps to instruction after '}', there are none) */
      
    case 2:
      puts("You entered 2.");
      break;
    
    case 3:
      puts("You entered 3.");
      break;
    
    case 4:
      puts("You entered 4.");
      break;
    
    case 5:
      puts("You entered 5.");
      exit(0);
    
    default:
      puts("Out of range, try again.");
  }
  return 0;
}


