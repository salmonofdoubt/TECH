/*
- Collatz Conjecture / Oneness / 3n+1 problem 
- http://xkcd.com/710/
- Details: task.pdf   

Your submission with number 9331834 for the problem 100 - The 3n + 1 problem has failed with verdict Wrong answer.

Although your program was successful at compilation and execution stages, it was not able of solving the proposed problem.

*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {
  
  in_out ( );
  exit(0);
}

int in_out ( ) {
  int lower, upper;

  while(scanf("%d %d", &lower, &upper) != EOF) {
    /*calc ( lower, upper );*/
    if (lower < 1 || upper > 9999 || lower >= upper)
      exit(0);
    printf("%d %d %d\n", lower, upper, calc( lower, upper ) );
    }    
  }
  
int calc (int lower_param, int upper_param ) {
  
  int i;
  int curr;
  int curr_cycle = 0;
  int max_cycle = 0;
  
  for (i = lower_param; i <= upper_param; i++) {
  curr = i;
  
  curr_cycle = 1;             /* Initial number not computed */
  while (curr > 1){
    curr_cycle++;
    if (curr % 2)             /* odd */
      curr = curr * 3 + 1; 
    else                      /* even */
      curr = curr / 2;
    }
    
    if (curr_cycle > max_cycle)
    max_cycle = curr_cycle;   /* retains biggest cycle number */
  }
  return max_cycle;           /* return this to calling function calc( )*/
}

