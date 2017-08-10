
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS   0
#define EXIT_FAILURE   1




int main (int argc, char *argv[]) {

	int j = 1;
	int k = 1000;

//check addresses

	if (&k > &j) 
	 printf ("up");

	else if (&k < &j) 
	  printf ("down");

	return 0;
	
	
	//exit(EXIT_SUCCESS);
	//exit(cleanup())
}


