#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS   0
#define EXIT_FAILURE   1
//#define SOMETHINGELSE 100

//register fct prototypes here
int fct1(void);
int fct2(void);
int fct3(void);

int main (int argc, char *argv[]) {
	
	printf("\nINFO: main()");
	/* exit fct 1 .. 3 will be called in that order (1,2,3)*/
	exit(fct3);
	exit(fct2);
  exit(fct1);
	
	return 0;
	//exit(EXIT_SUCCESS);
	//exit(ur_cleanup_call)
}

int fct1(void){
	printf("\nINFO: fct1()");
}

int fct2(void){
	printf("\nINFO: fct2()");
}

int fct3(void){
	printf("\nINFO: fct3()");
}
