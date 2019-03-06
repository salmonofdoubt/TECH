#include <stdio.h>

#define SOMETHING = 100


int main ( int argc, char *argv[] ){
  int x, y;
  x = 6 + (y = 4 + 5);
  printf("x = %d, y = %d", x, y);
}