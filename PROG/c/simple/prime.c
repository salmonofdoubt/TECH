//check if prime number. If not, calc the factor
#include <stdio.h>

int main(int argc, char *argv[]) {
  //---
  int n                             ;
  int i                             ;
  int flag = 1                      ;
  //---
  printf("Enter number N: ")        ;
  scanf("%d", &n)                   ;   
  //---
  for (i=2; (i<=(n/2)) && flag; ) {    // for as long as this is True..
  // to calc mod, i starts at 2
  // e.g. n=7, i=2:
  // for (True; (True && True))     
    if ((n %2) == 0) 
  // 7 %2 does not have remainder, so this is False...
      flag = 0                      ;
  // ... an flag goes 1, and we print (1).
    else
      i++                           ;
  }
  if (flag)
    printf("%d is prime\n", n)      ;
    //(1)
  else
    printf("Number %d is not prime, its smallest factor is %d.\n", n, i);
    //(2)
  return 0                          ;
}