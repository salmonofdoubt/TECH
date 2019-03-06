/* 
Day 5, 5.1.
Simple function
*/

#include <stdio.h>

long cube(long x);    //fct proto
long input, answer;   //vars

int main(void){
  printf("Integer value: ");
  scanf("%ld", &input);
  answer = cube(input); //retrieve the return value of this fct
  printf("\nCube of %ld is %ld.", input, answer);
  return 0;  
}

long cube(long x){
  long x_cubed;
  x_cubed = x*x*x;
  return x_cubed;
}

