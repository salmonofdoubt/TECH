//read number, then allow to enter n numbers and calc their sum
#include <stdio.h>

int main(int argc, char *argv[]) {
  //---
  int n     ; //amount of no.s to be entered
  int curr  ; //current no.
  int sum=0 ; //sum of all no.s received
  int i     ; //used for loop
  //---
  printf("\nAmount of numbers to be entered:\n")    ; 
  scanf("%d", &n)                                   ;
  for(i=1; i<=n; i++){
    printf ("Number: ")                             ;
    scanf  ("%d",&curr)                             ;
    sum = sum + curr                                ;
  }
  printf("Sum of these %d numbers is: %d\n",n, sum) ;
  return 0                                          ;
}