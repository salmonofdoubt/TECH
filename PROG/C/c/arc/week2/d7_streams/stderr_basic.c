/*
stderr cannot be redirected, it always goes to screen. 
Use your own error function:
*/

#include <stdio.h>
#include <stdaux.h>
#include <stdlib.h>

#define EXIT_SUCCESS   0
#define EXIT_FAILURE   1
//#define SOMETHINGELSE 100

//register fct prototypes here
void error_message(char *msg);

int main (int argc, char *argv[]) {

	/*
	... work
	*/
	
	error_message("An error has occurred.");
	return 0;
	//exit(EXIT_SUCCESS);
	//exit(cleanup())
}

void error_message(char *msg) {
	fprintf(stderr, msg);
	fprintf(stdaux, "Hello Auxiliary Port" );
}