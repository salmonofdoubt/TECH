/* LIST1304.c: Day 13 Listing 13.4 */
/* Demonstrates using an infinite loop to */
/* implement a menu system. */
 
#include <stdio.h>

int menu(void);

int main(void) {
	int choice;

	while (1) {
		choice = menu();
  
  	if (choice == 1) {
      puts("\nExecuting choice 1."); 
    }
  
  else if (choice == 2) {
      puts("\nExecuting choice 2.");
    }
  
  else if (choice == 3) {
      puts("\nExecuting choice 3.");
    }
  
  else if (choice == 4) {
      puts("\nExecuting choice 4.");
    }
  
  else if (choice == 5) {
      puts("\nExiting program now...");
      break;	/* terminates while (1) */ 
    }        
  else {
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
 
