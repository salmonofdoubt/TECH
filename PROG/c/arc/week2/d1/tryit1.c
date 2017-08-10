#include <stdio.h>
#include <stdlib.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  int one[1000], two[1000], three[1000];
  int four[10];
  int stuff[12][10];
  int i, j;
  
  for (i = 0; i<= 9; i++)
    four[i] = rand();
  
  for (i = 0; i <= 9;i++)
    printf("%d ",four[i]);
    
   
  for (i = 0; i < 12; i++) {
    for (j = 0; j <= 10; j++) {
      stuff[i][j] = rand();
    }
  }
     
  for (i = 0; i < 12; i++){
    for (j = 0; j < 10; j++){
      printf("\ni%d j%d -> %d", i, j, stuff[i][j] );
    }
    printf("\n");
  }
  
  return 0;
  //exit(EXIT_SUCCESS);
}