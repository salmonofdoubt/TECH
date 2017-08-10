//calculate factorial of a number
#include <stdio.h>
//5! = 5*4*3*2*1 = 120

int main(int argc, char *argv[]) {
  //---
  int n         ;   //no. that is entered                         
  int i         ;   //loop counter
  long long fact = 1  ;   //needs to be initialized
  //---
  printf("Enter number N: ")  ;
  scanf("%d", &n)             ;   
  //---
  for (i=1; (i<=n); i++) {
  //for (TRUE; TRUE; TRUE) //as long as all this is true
  fact *= i ;
  //            i   fact
  //--------------------
  // fact = 1     = 1           per initialization
  // fact = 1 * 1 = 1
  // fact = 1 * 2 = 2
  // fact = 2 * 3 = 6
  // fact = 6 * 4 = 24
  // fact = 24* 5 = 120
  }
   
  printf("%llu is the factorial of %d\n", fact, n);
  return 0  ;
}
