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