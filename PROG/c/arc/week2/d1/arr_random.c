/* LIST0803.c: Day 8 Listing 8.3 */
/* RANDOM.C -- Demonstrates using a */
/* multidimensional array */

//so my rewrite into different functions does not seem to work correctly 
 
#include <stdio.h>
#include <stdlib.h>
 
int main(void) {

  int randomarray, a,b,c;
  
  randomarray = init(10,10,10);
  
  for (a=0; a < 10; a++) {
    for (b=0; b < 10; b++) {
      for (c=0; c < 10; c++) {
        printf("just a tag %d %d %d", a, b, c);
      }
    }
  }
  
  printf("%d", printit(randomarray));
  return 0;
}

int init(int a, int b, int c){
  
  int randomo[10][10][10];
  for (a=0; a < 10; a++) {
    for (b=0; b < 10; b++) {
      for (c=0; c < 10; c++) {
          randomo[a][b][c] = rand();    // C library function rand()
      }
    }
  }
  return randomo[10][10][10];
}

int printit(int z[])

{
  int a,b,c;
  for (a=0; a < 10; a++) {              //printing it
    for (b=0; b < 10; b++) {
        for (c=0; c < 10; c++) {
            printf("\nrandomarray[%d][%d][%d] = " ,a, b, c);
            printf("%d", z);
        }
        printf("\nPress ENTER to continue," " CTRL-C to quit.");
        getchar();
    }
  }
  
}
  
  
