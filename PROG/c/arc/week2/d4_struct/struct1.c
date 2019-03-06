#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ){

  struct coord {
    int x;
    int y;
  } topleft, bottomleft;                // declared but not initilized

  //struct coord topleft, bottomleft;   //another option
  
  topleft.x = 10;                       //initializing
  topleft.y = 100;
  
   bottomleft.x = 20;
   bottomleft.y = 200;

  printf("topleft pair   : %d,%d\n", topleft.x, topleft.y);
  printf("bottomleft pair: %d,%d\n", bottomleft.x, bottomleft.y);
  
  topleft.x =  bottomleft.x + 20;     // making assignments
  topleft.y =  bottomleft.y + 40;
  
  printf("topleft pair   : %d,%d\n", topleft.x, topleft.y);
  
  //------------------------
  
  
  struct rectangle {
    struct coord topleft;
    struct coord bottomrt;
  } mybox;
  
  mybox.topleft.x = 0;
  mybox.topleft.y = 10;
  mybox.bottomrt.x = 100;
  mybox.bottomrt.y = 200;
  
  printf("\n\ntopleft pair   : %d,%d\n", topleft.x, topleft.y);
  printf("bottomleft pair: %d,%d\n", bottomleft.x, bottomleft.y);
  
  
  
  return 0;
}


