#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  // 1. Usage of typedef tag
  
  typedef struct {
    int x;
    int y;
    } coord;
  
  coord topleft, bottomright;
  
  topleft.x = 2;
  topleft.y = 5;
  bottomright.x = 7;
  bottomright.y = 6;
  
  printf("\n%d,%d", topleft.x, topleft.y);
  printf("\n%d,%d", bottomright.x, bottomright.y);
  
  // 2. Usage of struct tag
  
  struct coord{
    int x;
    int y;
    };
  
  struct coord top_left, bottom_right;
  
  top_left.x = 12;
  top_left.y = 15;
  bottom_right.x = 17;
  bottom_right.y = 16;
  
  printf("\n%d,%d", top_left.x, top_left.y);
  printf("\n%d,%d", bottom_right.x, bottom_right.y);
  
  
  
  return 0;
  //exit(EXIT_SUCCESS);
}