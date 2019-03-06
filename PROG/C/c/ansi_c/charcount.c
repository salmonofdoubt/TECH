/*
reads and prints number of chars
ctrl D == EOF
nl++ -> depend on nl's value before the increment
++nl -> depend on nl's value before the increment
*/
#include <stdio.h>
  
int B(){
  
  long input = 0;             /*initialize*/
  
  while (getchar() != EOF)  
    ++input;
  printf("%ld\n", chars);
  }
    
int main(){

  B();

}
