/* EXER0910: Day 9 Exercise 10 */
/* Combine the attendance of boys and girls in */
/* several classes to determine the total */
/* attendance of each class. */

#include <stdio.h>

#define LEN 10

int boys[LEN]   = {9, 10, 5, 8, 13, 7, 13, 9, 11, 9};
int girls[LEN]  = {8, 9, 12, 16, 7, 10, 11, 13, 10, 9};
int attend[LEN];
int i;

int * addarrays(int x[], int y[], int z[], int arrsize);
int *p_arr;

int main(void) {

  p_arr = addarrays(boys, girls, attend, LEN);
  
  /* Print totals for each class. */
  printf("Totals per Class\n"); 
  printf("Class #\tBoys\tGirls\tTotal\n");
  
  for (i = 0; i < LEN; i++)  {
    printf("  %d\t  %d\t  %d\t  %d\n", 
          (i + 1), boys[i], girls[i], *(p_arr + i));
  }
  return 0;
}


int * addarrays(int x[], int y[], int totarray[], int arrsize) {
  int i;

  for (i = 0; i < arrsize; i++)
    totarray[i] = x[i] + y[i];

  return (totarray);
}