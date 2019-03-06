#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  struct part {
    int number;
    char name[10];
  } ;
    
  struct part *p_part;
  (*p_part).number = 100;
  
  printf("%d", p_part->number);
    
  return 0;
  //exit(EXIT_SUCCESS);
}


