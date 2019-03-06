#include <stdio.h>

/*
return-type function-name(parameter declarations, if any) {
  declarations
  statements
}

*/

int power(int base, int n){       
/* (int int) would have done it if base and n were declared vars*/

  int i, p;                       /* are local here */
  p = 1;
  
  for (i = 1; i <= n; ++i)        /* n will be given by caller */
    p = p * base;
  return p;                       /* returns the value of p as int to the caller */
}


main(){
  
  int i;                          
  
  printf("\tn\tBase2^n\tBase3^n\n");
  printf("\t------\t------\t------\n");
  for (i = 0; i <= 5; ++i)  
    printf("\t%d \t%d \t%d\n", i, power(2,i), power(3,i));  
                                  /* calls power with base and i */
  return 0;
}

