#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS	 0
#define EXIT_FAILURE	 1
//#define SOMETHINGELSE 100

//register fct prototypes here

int main (int argc, char *argv[]) {
	
	int choice;
	
	printf("\nEnter choice 1 or 2:");
	scanf("%d",&choice);
	
	if (choice == 1)
		printf("\nchoosed 1");
		
	else if (choice == 2) 
		printf("\nchoosed 2");

	else
		printf("\ninvalid");
	
	
	return 0;
	exit(EXIT_SUCCESS);
	
	//exit(EXIT_SUCCESS);
	//exit(cleanup())
}