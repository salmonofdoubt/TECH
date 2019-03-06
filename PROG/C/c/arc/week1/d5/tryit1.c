#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here
int product(int a, int b);
float divide(float a, float b);

int main ( int argc, char *argv[] ){
  printf("Product of 3 and 4 is: %d\n", product(3,4));
  printf("Dividing 3 by 4 is: %2.3f\n", divide(3,4));
  
  return 0;
  //exit(EXIT_SUCCESS);
}


float do_it(char a, char b, char c){
  
}


int product(int a, int b){
  int c = a*b;
  return c;
}

float divide(float a, float b){
  float c = 0;
  
  if (b > 0) 
    {
    c = a/b;
    }
    else 
      c = 0;
  return c;
}


