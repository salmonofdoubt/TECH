/*
- Problem proposed:   Block Problem
- Details:            readme.pdf
- Notes:
   - at any one time there can only be 10 block
   - scan vertically and stop if encounter -1 
- Compile:            gcc -o vX vX.c -lm -pipe -O2 -ansi
- Backup:             scp -r -v ../../../_uva/ abaumann@172.25.132.50:www/no_crawl/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ) {

  int array[10][10], i, j;
  int source, dest, m;
  char action[5], place[5];
  /* action: move||pile. place: over||onto. +1 char for NULL. */

	for(i = 0; i <= 9; i++) {       /* Initialize 0th line with 0..9 */  
	  array[0][i] = i;
  }

  for(i = 1; i <= 9; i++){        /* Initialize 1st..9th line with -1 */ 
	  for(j = 0; j <= 9; j++){
	  array[i][j] = -1;
	  }
	}

	printarray(array, 10, 10);       /* call array state */  
	
	scanf("%4s", action);           /* input starts here */
	
  while( strcmp (action, "quit") != 0 ) { 
	  scanf("%d %4s %d", &source, place, &dest);
    
    if      (strcmp (action, "move") == 0 && strcmp (place, "over") == 0)
      moveover(source, dest, array);
    else if (strcmp (action, "move") == 0 && strcmp (place, "onto") == 0) 
      moveonto(source, dest, array);
    else if (strcmp (action, "pile") == 0 && strcmp (place, "over") == 0) 
      pileover(source, dest, array);
    else if (strcmp (action, "pile") == 0 && strcmp (place, "onto") == 0) 
      pileonto(source, dest, array);
    else
      printf("\nNot calling anything\n");
      
    printf("---\naction:\t%s\nsource:\t%d\nplace:\t%s\ndest:\t%d\n", action, source, place, dest );
    scanf("%4s", action);
  }
}

int printarray(int arr[][10], int size_x, int size_y){    /* printing, not creating array */
  int i, j;
	printf("\t____________________________________________________________________________\n");
		
	for(i = 0; i < size_x; i++){
	  for(j = 0; j < size_y; j++){
	    printf("\t%d ", arr[i][j]);
	  }
	  printf("\n");
  }
 printf("\t____________________________________________________________________________\n");
}

int moveover(int arr[][10], int size_x, int size_y ) {    /* modify the external array */
  printf("\ncalled fct MOVEOVER\n");
  

  int i, j;
  for(i = 0; i <= 9; i++){                //find dest and placc b
	  for(j = 1; j <= 9; j++){
	    if (arr[i][j] = size_y && arr[i][j+1] == -1){
        arr[i][j+1] = size_x;
	    }
    }
  }
}

int moveonto(int arr[][10], int size_x, int size_y ) {     
  printf("\ncalled fct MOVEONTO\n");
}

int pileonto(int arr[][10], int size_x, int size_y ) {     
  printf("\ncalled fct PILEONTO\n");
}

int pileover(int arr[][10], int size_x, int size_y ) {     
  printf("\ncalled fct PILEOVER\n");
}
