/*
- Block Problem,
- Details: readme.pdf
- Compile: gcc -o vX vX.c -lm -pipe -O2 -ansi
- Notes:
   - at any one time there can only be 10 block
   - scan vertically and stop if encounter -1 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ) {

  int array[10][10], i, j;
  
  char action;  /*move, pile*/
  char place;   /*over, onto*/   
  int source, dest;
    
	for(i = 0; i <= 9; i++){          /* Initialize 0th line with 0..9 */  
	  array[i][0] = i;
	  //printf("\ti%d", array[i][0]);
  }
  for(i = 0; i <= 9; i++){          /* Initialize 1st..9th line with -1 */ 
	  for(j = 1; j <= 9; j++){
	  array[i][j] = -1;
	  }
	  //printf("\tj%d\n", array[i][j]);
	}
	
	/* checking: */
  printf("\t____________________________________________________________________________\n");
		
	for(j = 0; j <= 9; j++){
	  for(i = 0; i <= 9; i++){
	    printf("\t%d ", array[i][j]);
	  }
	  printf("\n");
  }
  printf("\t____________________________________________________________________________\n");
	
/* should look like this:
i -
j  0  1  2  3  4  5  6  7  8  9 
| -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
  
  scanf("%5s %d %5s %d", &action, &source, &place, &dest);  
  /* checking input: */
  printf("\naction:\t%s\nsource:\t%d\nplace:\t%s\ndest:\t%d", &action, source, &place, dest);
  

  exit(0);
}

int moveonto(int a, int b) {
    
}

int moveover(int a, int b) {
  
}

int pileonto(int a, int b) {
  
}

int pileover(int a, int b) {
  
}


