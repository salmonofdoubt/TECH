#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  int eightyeight[88];
  int x;

  for (x = 0; x < 88; x++)
    eightyeight[x] = 88;
  for (x = 0; x < 88; x++)  
    printf("%d, ",eightyeight[x]);
  return 0;
  //exit(EXIT_SUCCESS);
}




/* LIST0801.c: Day 8 Listing 8.1 */
/* EXPENSES.C – Demonstrates use of an array */
 
#include <stdio.h>
 
/* Declare an array to hold expenses, and a */
/* counter variable. */
 
float expenses[13];
int count;
 
int main(void) {
  /* Input data from keyboard into array. */
  
  for (count = 1; count < 13; count++) {
    printf("Enter expenses for month %d: ", count);
    scanf("%f", &expenses[count]);
  }
  
  /* Print array contents. */
  
  for (count = 1; count < 13; count++) {
    printf("\nMonth %d = $%.2f", count,
            expenses[count]);
  }
  return 0;
}
