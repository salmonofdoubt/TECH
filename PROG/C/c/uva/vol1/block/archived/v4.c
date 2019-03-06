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

  int array[10][5], i, j;
  int source, dest, m;
  char action[5], place[5], test[5];          
  /* action: move||pile. place: over||onto. +1 char for NULL. */
  
	for(i = 0; i <= 9; i++) {       /* Initialize 0th line with 0..9 */  
	  array[0][i] = i;
  }
  
  for(i = 1; i <= 9; i++){        /* Initialize 1st..9th line with -1 */ 
	  for(j = 0; j <= 4; j++){
	  array[i][j] = -1;
	  }
	}

	printarray(array, 10, 5);       /* call array state */  
	scanf("%4s", test);             /* input happens here */
  while( strcmp (test, "quit") != 0 ) { 
	  scanf("%d %4s %d", &source, place, &dest);
	  scanf("%4s", action);
	  //scanf("%4s", test); 
    printf("\nAll SCANF'ed \naction:\t%s\nsource:\t%d\nplace:\t%s\ndest:\t%d\n", action, source, place, dest );
    
    if ( strcmp (action, "move") == 0 && strcmp (place, "over") == 0)
      moveover(source, dest, array);   
    else
      printf("\nNot calling moveover\n");
  }
}
/*
  if (action == 'move' && place == 'onto')
    moveonto(source, dest);

  if (action == 'pile' && place == 'over')
    pileover(source, dest);

  if (action == 'pile' && place == 'onto')
    pileonto(source, dest);
*/

	
int printarray(int arr[][5], int size_x, int size_y){    /* printing, not creating array */
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

int moveover(int a, int b, int arr[][10], int size_x, int size_y ) {     
/* this will modify the external array */
  printf("\ncalled moveover\n");
  int i, j;                /* need array from main here */
  
  for(i = 0; i <= 9; i++){                /* find dest and placc b */
	  for(j = 1; j <= 9; j++){
	    if (arr[i][j] = b && arr[i][j+1] == -1){
        arr[i][j+1] = a;
	    }
    }
  }
  exit(0);
}

int moveonto(int a, int b) {

}


int pileonto(int a, int b) {
  
}

int pileover(int a, int b) {
  
}


