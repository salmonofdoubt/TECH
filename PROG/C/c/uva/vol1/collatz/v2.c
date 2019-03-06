/*
- Collatz Conjecture / Oneness / 3n+1 problem 
- http://xkcd.com/710/
- Details: task.pdf

- gcc -o v2 v2.c -lm -pipe -O2 -ansi
- ./v2 < input.txt > output.txt

- Notes: Returns correct results when cc and gcc compiled (Mac, Ubiquity) 
         When making UVA submission, says runtime error:
         "...Remember to always terminate your code with the exit code 0."
         Not sure what might be missing there.  

 - what happens if the cycle length for "upper" is bigger than the
   cycle length for "upper-1"?

*/



#include <stdio.h>
#include <stdlib.h>

int lower, upper;
int i;
int curr;
int curr_cycle, max_cycle = 0;

int main ( int argc, char *argv[] ) {
  
  in_out ( );
  exit(0);
}

int in_out ( ) {
  
  while(scanf("%d %d", &lower, &upper) != EOF) {
    calc ( );
    printf("%d %d %d\n", lower, upper, max_cycle);
    }
    
  if (lower < 1 || upper > 10000 || lower >= upper)
    exit(EXIT_FAILURE);
}
  
int calc ( ) {
  
  
  
  for (i = lower; i <= upper; i++) {
  curr = i;
    
  if (curr_cycle > max_cycle)
    max_cycle = curr_cycle;   /* retains biggest cycle number */
    
  curr_cycle = 1;             /* Initial number not computed */
  while (curr > 1){
    curr_cycle++;
    if (curr % 2)             /* is odd */
      curr = curr * 3 + 1; 
    else                      /* must be even */
      curr = curr / 2;
    }
  }
}

