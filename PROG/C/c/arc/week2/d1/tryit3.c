/* LIST0803.c: Day 8 Listing 8.3 */
/* RANDOM.C -- Demonstrates using a */
/* multidimensional array */
 
#include <stdio.h>
#include <stdlib.h>
 
/* Declare a three-dimensional array with 1000 8?
/* elements. */
 
int randomo[1000];
int a;
long total = 0;
 
int main(void) {
  for (a=0; a < 1000; a++){
    randomo[a] = rand();
    total += randomo[a];
    }
  total /= 1000;
  printf("Average of 1000 random ints: %ld", total);
    
  
  printf("\nPress ENTER to print all numbers," " CTRL-C to quit.");
  getchar();

  for (a=0; a < 1000; a++) {
    printf("\nrandomo[%d] = ", a);
    printf("%d", randomo[a]);
  }
  return 0;
}

int average_calc(int x){
  
}