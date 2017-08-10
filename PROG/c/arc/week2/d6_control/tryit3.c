/* LIST1307.c: Day 13 Listing 13.7 */
/* Demonstrates using an infinite loop and the */
/* switch statement to implement a menu system. */
#include <stdio.h>
#include <stdlib.h>

int menu(void);
int execute_ls(void);
int execute_ps(void);
int execute_top(void);

int main(void) {
	
	printf("---SysCommands---");
	
	while (1) {
		switch( menu() ) { 
		/* switch()'s arg is return from menu(). */
		/* when menu() is called it also prints something of its own. */
			case 1:		/*case statemets don't need '{}'. */
				puts("\nExecuting --ls--.");
				execute_ls();
				break;
			
			case 2:
				puts("\nExecuting --ps--.");
				execute_ps();
				break;
				
			case 3:
				puts("\nExecuting --top-- \nctrl/C to exit.");
				execute_top();
				break;
				
			case 4:		 /* Exit program. */ 
				puts("\nExiting program now...");
				exit(0);
			
			default:
				puts("Invalid choice, try again.");
				break;
		}
	} 
	return 0;
}

int menu(void) {
/* Displays a menu and inputs user's selection. */
	int reply;
	
	puts("\nEnter 1 for ls");
	puts("Enter 2 for ps.");
	puts("Enter 3 for top.");
	puts("Enter 4 to exit program.");
	
	scanf("%d", &reply);
	return reply;
}

int execute_ls(void){
	system("ls");
	return 0;
}

int execute_ps(void){
	system("ps");
	return 0;
}

int execute_top(void){
	system("top");
	return 0;
}