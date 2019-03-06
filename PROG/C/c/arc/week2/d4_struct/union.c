#include <stdio.h>
 
/*
Unions are similar to structures. A union is declared and used in the same ways that a structure is. A union differs from a structure in that only one of its members can be used at a time. The reason for this is simple. All the members of a union occupy the same area of memory. They are laid on top of each other.
*/

union shared {
  char c;
  int i;
  };

/*
This union, shared, can be used to create instances of a union that can hold either a character value c or an integer value i. This is an OR condition. Unlike a structure that would hold both values, the union can only hold one value at a time.
*/

//Only the 1st member can be initilized, here it is a char called generic_variable:
union shared generic_variable = {'@'};

int main(void) {  
  return 0;
}
 
