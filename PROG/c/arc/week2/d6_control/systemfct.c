/* 
system()
*/

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS   0
#define EXIT_FAILURE   1
//#define SOMETHINGELSE 100

//register fct prototypes here

int main ( int argc, char *argv[] ){
	system("ls");
	return 0;
 	//exit(EXIT_SUCCESS);
	//exit(ur_cleanup_call)
}