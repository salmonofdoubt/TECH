/*
- Problem proposed:   Block Problem
- Details:            readme.pdf
- Notes:
   - at any one time there can only be 10 blocks
   - scan vertically and stop if encounter -1 
- Compile:            gcc -o vX vX.c -lm -pipe -O2 -ansi
- Backup:             scp -r -v ../../../_uva/ abaumann@172.25.132.50:www/no_crawl/.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_row;
int g_col;

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
  
  printf("\nORIGINAL ARRAY:\n");
	printarray(array, 10, 10);        /* call array state */  
	
	scanf("%4s", action);             /* input starts here */
	
  while( strcmp (action, "quit") != 0 ) { 
	  scanf("%d %4s %d", &source, place, &dest);
    
    if      (strcmp (action, "move") == 0 && strcmp (place, "over") == 0) {
      moveover(source, dest, array);
    }
    else if (strcmp (action, "move") == 0 && strcmp (place, "onto") == 0) { 
      moveonto(source, dest, array);
    }
    else if (strcmp (action, "pile") == 0 && strcmp (place, "over") == 0) {
      pileover(source, dest, array);
    }
    else if (strcmp (action, "pile") == 0 && strcmp (place, "onto") == 0) {
      pileonto(source, dest, array);
    }
    else
      printf("\n\nDO NOTHING:\n\n\n");
      
    printarray(array, 10, 10); //test

    //printf("\ninput was:\naction:\t%s\nsource:\t%d\nplace:\t%s\ndest:\t%d\n\n==================================================================================\n", action, source, place, dest );
    
    scanf("%4s", action);
  }
}

int printarray(int arr[][10], int size_x, int size_y){    /* printing, not creating array */
  int i, j;
	printf("\t__________________________________________________________________________\n");
		
	for(i = 0; i < size_x; i++){
	  for(j = 0; j < size_y; j++){
	    printf("\t%d ", arr[i][j]);
	  }
	  printf("\n");
  }
 printf("\t__________________________________________________________________________\n");
}


int find(int aorb, int arr[][10], int size_x, int size_y ){
  int i,j;
  for (i = 0; i < size_x; i++){
     for (j = 0 ; j < size_y ; j++){
       if (arr[i][j] == aorb)
         g_row = i;
         g_col = j;
     }
  }
}


int moveover(int a, int b, int arr[10][10]) {    
/* 
put block a on top of stack containing b, after returning any blocks that are stacked ontop of a to their original positions. 
*/
  
  int i, j, k, tmp = a;
  
  printf("\n\nMOVEOVER:");
  printf("\n%d %d\n", a, b);
  
  //currently  calling find//
  find(a, arr, 10, 10);
  //for(i = 0; i <= 9; i++){
  //  for(j = 0; j <= 9; j++){
  //    if (arr[i][j] == a){
        arr[i][j] = -1;
        for (i = i+1; i <= 9; i++){
          if (arr[i][j] != -1){
           k = arr[i][j];
           arr[0][k] = k;
           arr[i][j] = -1;
          }
        }
  //    }                
  //  }
  //}
  //find(b, arr, 10, 10);
  for(i = 0; i <= 9; i++){
    for(j = 0; j <= 9; j++){
      if (arr[i][j] == b) {
        for (i = i+1; i <= 9; i++){         
          if (arr[i][j] == -1) {
              arr[i][j] = tmp;
              i = 9;
          }
        }
      }
    }
  }
}


int moveonto(int a, int b, int arr[10][10] ) {  
/* 
put block a directly onto b, after returning any blocks that are stacked ontop of a or b to their original positions. 
*/
  int i, j, k, tmp = a;
   
  printf("\n\nMOVEONTO\n");
  printf("\n%d %d\n", a, b);
 
  for(i = 0; i <= 9; i++){
    for(j = 0; j <= 9; j++){
      if (arr[i][j] == a){
        arr[i][j] = -1;
        for (i = i+1; i <= 9; i++){
          if (arr[i][j] != -1){
           k = arr[i][j];
           arr[0][k] = k;
           arr[i][j] = -1;
          }
        }
      }          
    }
  }

  for(i = 0; i <= 9; i++){
    for(j = 0; j <= 9; j++){
      if (arr[i][j] == b) {
        for (i = i+1; i <= 9; i++){         
          if (arr[i][j] == -1) {
              arr[i][j] = tmp;
              i = 9;
          }
        }
      }
    }
  }
}

int pileonto(int a, int b, int arr[][10] ) {     
  printf("\n\nPILEONTO\n");
}

int pileover(int a, int b, int arr[][10] ) {     
  printf("\n\nPILEOVER\n");
}
