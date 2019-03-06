#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  int cost = 10;
  int interest = 1;
  
  struct data {
    int *value;
    int *rate;
    char *p1;
  } first;
  
  first.value = &cost;
  first.rate = &interest;
  first.p1 = "DPEC";
  
  printf("%d, %d, %s", *first.value, *first.rate, first.p1);
  // why char pointer does not have to be derefed is not clear
  
  return 0;
  //exit(EXIT_SUCCESS);
}