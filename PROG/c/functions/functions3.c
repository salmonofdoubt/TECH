/* 
Determine largest number in input*/

#include <stdio.h>

int getint(void); /* prompts user to enter an integer, which it returns*/

int getmax(int a, int b, int c); /* returns value of largest of a, b, c*/

int main (void) {
  int x, y, z;      //declare ints

  x = getint();     //initialize ints via calling a function
  y = getint();
  z = getint();
  printf("The largest of %d, %d, and %d is %d\n", x, y, z, getmax(x,y,z));
}

int getint(void) {
  int a;

  printf("Enter an integer > ");
  scanf("%d", &a);
  return(a);
}

int getmax(int a, int b, int c){
  int m = a;

  if ( m < b )
    m = b;
  if ( m < c )
    m = c;
  return(m);
}