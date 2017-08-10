/* LIST1307.c: Day 13 Listing 13.7 */
/* Demonstrates using an infinite loop and the */
/* switch statement to implement a menu system. */
#include <stdio.h>
#include <stdlib.h>

int menu(void);
 
int main(void) {
	while (1) {
		switch( menu() ) { 
		/* switch()'s arg is return from menu(). */
		/* when menu() is called it also prints something of its own. */
			case 1:		/*case statemets don't need '{}'. */
				puts("\nExecuting choice 1.");
				break;
			
			case 2:
				puts("\nExecuting choice 2.");
				break;
			
			case 3:
				puts("\nExecuting choice 3.");
				break;
			
			case 4:
				puts("\nExecuting choice 4.");
				break;
			
			case 5:		 /* Exit program. */ 
				puts("\nExiting program now...");
				exit(0);
			
			default:
				puts("Invalid choice, try again.");
		}
	} 
	return 0;
}

int menu(void) {
/* Displays a menu and inputs user's selection. */
	int reply;
	
	puts("\nEnter 1 for task A.");
	puts("Enter 2 for task B.");
	puts("Enter 3 for task C.");
	puts("Enter 4 for task D.");
	puts("Enter 5 to exit program.");
	
	scanf("%d", &reply);
	return reply;
}