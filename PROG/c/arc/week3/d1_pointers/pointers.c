/*

*/
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS   0
#define EXIT_FAILURE   1
//#define SOMETHINGELSE 100

//register fct prototypes here

int main (int argc, char *argv[]) {
	
	/* x is a type int variable. */
	int x = 12;
	/* ptr points to x. */
	int *ptr = &x;
	/* ptr_to_ptr points to a pointer to x */
	int **ptr_to_ptr = &ptr; 
	
	printf("%d", **ptr_to_ptr);

	return 0;
	//exit(EXIT_SUCCESS);
	//exit(cleanup())
}