/* LIST0605.c: Day 6 Listing 6.5 */
/* Demonstrates a simple do...while statement */
 
#include <stdio.h>
 
int get_menu_choice(void);
 
int main(void) {
  int choice;
  
  choice = get_menu_choice();
 
  printf("You chose Menu Option %d", choice);
  return 0;
}
 
int get_menu_choice(void) {
    int selection = 0;
    
    do {
        printf("\n");
        printf("\n1 - Add a record");
        printf("\n2 - Change a record");
        printf("\n3 - Delete a record");
        printf("\n4 - Quit");
        printf("\n");
        printf("\nEnter a selection:");
        
        scanf("%d", &selection);
        
    }while (selection < 1 || selection > 4);
 
    return selection;
}


for (count = 1; count < 100; count++)
  {
  do
    {
    /* the do...while loop */
    }   /* end of for loop */
    } while (x != 0);