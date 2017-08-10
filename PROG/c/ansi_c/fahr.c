#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEPSIZE 20                           
/*
- symbolic vars or constants UPPERCASE
*/
  
void B(){
  
  int fahr;
  
  for (fahr = LOWER; fahr <= UPPER; fahr += STEPSIZE)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
 
int main(){

  B();
    
}

