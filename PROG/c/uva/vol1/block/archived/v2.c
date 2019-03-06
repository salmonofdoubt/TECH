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

int main ( int argc, char *argv[] ) {

  int array[10][10], i, j;
  
  char movepile, overonto;
  int source, dest;

  /*Initialize an array*/      
	for(i = 0; i <= 5; i++){
    for(j = 0; j <= 5; j++)
			array[i][j] = i;
		}
		
  for(i = 0; i <= 5; i++)
		printf("\t%d:", i);
	printf("\n");

	for(j = 0; j <= 5; j++){
		printf("%d:", j);
		for(i = 0; i <= 5; i++)
			printf("\t%d", array[i][j]);
		printf("\n");
		}
  

/* 
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

  scanf("%s %d %s %d", &movepile, &source, &overonto, &dest);  
  printf("\nmovepile: %s\nsource: %d\noveronto: %s\ndest %d\n", &movepile, source, &overonto, dest);
   
  exit(0);
}

/* 
if (movepile == 'move')

*/

int moveonto( ){

    
}

int moveover( ){
  
}

int pileonto( ){
  
}

int pileover( ){
  
}


