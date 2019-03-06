//swap, works only using addresses and pointers

#include <stdio.h>

int main(int argc, int *argv[]) {

  int a = 3;
  int b = 7;
  
  printf("b4 swap:\t a = %d, b = %d\n", a, b);
  
  swap (&a, &b);                                      
//caller uses & to compute pointers to its local mem (a, b) 
  
  printf("after swap:\t a = %d, b = %d\n", a, b);
}

int swap(int *x, int *y){                             
//callee fct: params are int pointers

  int temp;

//callee function uses * to dereference the formal parameter pointers back to get callers mem   
    temp = *x;                                      
    *x = *y;
    *y = temp;    
}
