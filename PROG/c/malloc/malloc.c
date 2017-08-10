//malloc demo / usage 

#include <stdio.h>
#include <stdlib.h>          

int main(int argc, char *argv[]) {
	
	// :( 10000B on STACK, have 10000 of these > overrun
	//char str[10000];
	//int x[10000]; 
	
	// :) use pointer instead, then malloc() which space is on heap:	
	char *ptrStr = NULL;
	ptrStr = malloc(10000);
	
	int *ptrx = NULL;
	ptrx = malloc(4 * 10000);
	//or
	ptrx = (int *)malloc(10000 * sizeof(int));

	if (ptrx == 0){
		printf("ERROR: Out of memory\n");
		return 1;
	}
	
	*ptrx = 411;
	printf("%d\n", *ptrx);
	
	//always always free up the heap!
	free(ptrx);
	
	return 0;
}
