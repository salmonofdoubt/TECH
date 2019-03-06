#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here
float average(float a, float b, float c, float d, float e);

int main ( int argc, char *argv[] ){
  float z;
  float a,b,c,d,e;
  
  printf("Enter 5 integers: \n");
  scanf("%f%f%f%f%f", &a,&b,&c,&d,&e);
  z = average(a, b, c, d, e);
  
  printf("Average is: %2.2f\n", z);
  return 0;
  //exit(EXIT_SUCCESS);
}

float average(float a, float b, float c, float d, float e){
  return ((a+b+c+d+e)/5);
}
  




