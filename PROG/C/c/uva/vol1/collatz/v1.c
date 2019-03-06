#include <stdio.h>  
#include <stdlib.h>               /* call exit*/

/*
ANSinputC 4.1.2 - GNU C Compiler options:
gcc -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
*/

int main ( int argc, char *argv[] ){

  int input; 
  int count = 0;
  
  printf("---3n+1 NP---\n");

  printf("Enter: ");
  scanf("%d", &input);
  printf("%d\n", input);
  
  if (input < 1 || input > 10000)
    exit(EXIT_FAILURE);
  
  while (input > 1){
    count++;                        /* count loops */
      if (input % 2){                 /* test odd */
        input = input * 3 + 1   ;
        printf("%d\n", input) ;
      }
      else {                          /* test even */
        input = input / 2       ;
        printf("%d\n", input) ;
      }
    }  
    count++;
  printf("(count: %d)", count);
  
  exit(EXIT_SUCCESS);
}