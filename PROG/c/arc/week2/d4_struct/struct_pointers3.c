/* LIST1104.c: Day 11 Listing 11.4 */
/* Demonstrates stepping through an array of  */
/* structures using pointer notation. */
 
#include <stdio.h>
 
#define MAX 4
 
/* Define a structure, then declare and */
/* initialize an array of 4 structures. */
struct part{
    int number      ;
    char name[10]   ;
  } data[MAX] = {                       //initilizing array
                    1, "Smith",
                    2, "Jones",
                    3, "Adams",
                    4, "Wilson"
                  } ;
 
/* Declare a pointer to type part, and a counter variable. */
struct part *p_part;
int i;
 
int main(void) {
  /* Initialize the pointer to the first array element. */
  p_part = data;
  
  /* Loop through the array, incrementing the */
  /* pointer with each iteration. */
  for (i = 0; i < MAX; i++) {
      printf("\nAt address %d: %d %s", p_part, p_part->number,
                                                  p_part->name);
      p_part++;    
  }
  return 0;
}