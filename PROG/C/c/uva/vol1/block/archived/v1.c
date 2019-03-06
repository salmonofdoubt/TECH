/*
- Collatz Conjecture / Oneness / 3n+1 problem 
- http://xkcd.com/710/
- Details: task.pdf
- Notes: Returns correct results when cc and gcc compiled (Mac, Ubiquity) 
         When making UVA submission, says runtime error:
         "...Remember to always terminate your code with the exit code 0."
         Not sure what might be missing there.  
*/

#include <stdio.h>
#include <stdlib.h>

int lower, upper;
int i;
int curr;
int curr_cycle, max_cycle = 0;

int main ( int argc, char *argv[] ) {

  input ();
  calc ();
  printf("\n%d %d %d", lower, upper, max_cycle);
  exit(0);
}

int input () {
  printf("\n---3n+1 NP---");
  printf("\nEnter lower <space> upper limit: ");
  fflush(stdout);
  scanf("%d %d", &lower, &upper);
  
  if (lower < 1 || upper > 10000 || lower >= upper)
    exit(EXIT_FAILURE);
}
  
int calc () {
  for (i = lower; i <= upper; i++) {
  curr = i;
    
  if (curr_cycle > max_cycle)
    max_cycle = curr_cycle;   /* retains biggest cycle number */
    
  curr_cycle = 1;             /* Initial number not computed */
  while (curr > 1){
    curr_cycle++;
    if (curr % 2)             /* means is odd */
      curr = curr * 3 + 1; 
    else                      /* so must be even */
      curr = curr / 2;
    }
  }
}

