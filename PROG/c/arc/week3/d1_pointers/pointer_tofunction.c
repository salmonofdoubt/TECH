/* LIST1508.c: Day 15 Listing 15.8 */
/* Demonstration of declaring and  */
/* using a pointer to a function. */

/*
the type specification, a variable can be a function pointer
int (*)()i;

1. int f();
2. i = &f; 

int f(char );
int (*fn)(char);
fn = &f; which is the same as fn = f; but that's not good

fn = malloc(sizeof((*)(char)))

*/
 
#include <stdio.h>
 
/* The function prototype. */
float square(float x);
 
/* The pointer declaration. */
float (*p)(float x);


int main(void) {
  /* Initialize p to point to square(). */
  
  p = square;
  
  /* Call square() two ways. */
  
  printf("\ncalling square(): %f, or p: %f", square(6.6), p(6.6));
  return 0;
}
 
float square(float x) {
  return x * x;
}