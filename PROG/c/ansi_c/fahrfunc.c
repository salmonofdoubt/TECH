#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEPSIZE 20                           
/*
- no ";" in header
- symbolic vars or constants UPPERCASE
*/
  
int main(){
  
  int fahr;
  
  for (fahr = LOWER; fahr <= UPPER; fahr += STEPSIZE)
    printf("%3d %6.1f\n", fahr, conversion());
}
 
float conversion(){

  int fahr; 
  float res;
  
  for (fahr = LOWER; fahr <= UPPER; fahr += STEPSIZE)
  res = (5.0/9.0)*(fahr-32))
    return res;
  
    
}


/*
int power(int base, int n){       // (int int) would have done if base and n were declared vars

  int i, p;                       /* are local here 
  p = 1;
  
  for (i = 1; i <= n; ++i)        /* n will be givnen by caller 
    p = p * base;
  return p;                       /* returns the value of p as int to the caller 
}


main(){
  
  int i;                          
  
  printf("\tn\tBase2^n\tBase3^n\n");
  printf("\t------\t------\t------\n");
  for (i = 0; i <= 5; ++i)  
    printf("\t%d \t%d \t%d\n", i, power(2,i), power(3,i));   /* calls power with base and i 
  return 0;
}
