#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

void print_it(int x);



int main ( int argc, char *argv[] ){
	int var = 1;
	print_it(var);
  return 0;
  //exit(EXIT_SUCCESS);
}

void print_it(int x){
	printf("var =%d", x);
}