#include <stdio.h>


int marray[] = {23,34,5,67,8};
    
int main ( int argc, char *argv[] ){
  
  int *ptr;
  ptr = &marray[0];
  int i;
  
  for (i = 0; i < 4; i++){
    printf("marray[%d] = %d\n", i, *ptr);
    *ptr++;
  }
}

/* 
marray[0] = 23
marray[1] = 34
marray[2] = 5
marray[3] = 67
*/