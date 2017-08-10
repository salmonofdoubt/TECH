/*
incorrect sample of passing parameters by value
*/

#include <stdlib.h>
#include <stdio.h>


int main(int argc, int *argv[]) {

  int a = 2011;
//call f with parameter a, which is 2011
    f(a);
  printf("In main function, and after passing:\n%d\n", a);
    
}

int f(int x){
  
  x++;
  printf("Exists only in f function:\n%d\n", x);

}



