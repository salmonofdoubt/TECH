/*
prints out the first Fibonacci series
0
  1 
0+1=1
0 1+1=2
0 1 1+2=3
0 1 1 2+3=5
0 1 1 2 3 5=8
0 1 1 2 3 5+8=13
0 1 1 2 3 5 8+13=21
0 1 1 2 3 5 8 13+21=34
*/   
                     
#include <stdio.h>

int main(void) {
    int n;                    // the lenght of fibonacci series
    int i;                    // counter 
    int curr = 0;             // current fibo 
    int right_neighbour = 1;  // value of current's right_neighbour
    int sum;                  // sum  
    //---
    printf("Fib no.'s to calculate: ");
    scanf("%d", &n);  //stick input into address of n
    //---
    if (n <= 0)           
       printf("Expect positive number really.\n");
    else {
      printf("\n\n\ti \t Fibonacci(i) \n\t=====================\n");
    //------  
      for (i=0; i <= n; i++) {
      //go through this n-many times
	      printf("\t%d \t   %d\n", i, curr);
	      sum             = curr + right_neighbour  ; 
	      curr            = right_neighbour         ; 
	  	  right_neighbour = sum                     ; 
      }
    }
}


