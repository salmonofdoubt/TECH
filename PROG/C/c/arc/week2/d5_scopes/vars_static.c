/* LIST1204.c: Day 12 Listing 12.4 */
/* Demonstrates automatic and static local */
/* variables. */

/*
The static variable x increases with each iteration as it retains its value between calls.
The automatic (local) variable y is reinitialized to 0 with each call to func1().
*/
 
#include <stdio.h>
 
void func1(void);
 
int main(void) {
  int count;
  
  for (count = 0; count < 20; count++) {
     printf("MAIN: Iteration %d: ", count);
     func1();
  }   
  return 0;
}

 
void func1(void) {
  static int x = 0;
  int y = 0;
  
  printf("FUNC1: x = %d, y = %d\n", x++, y++);
}

/*
PS 1: 
- An ordinary external variable (vars_extern.c) is visible to all functions
in the file and can be used by functions in other files. 
- A static external variable is visible only to functions in its own file
and below the point of definition.
- Static lifetime is from it's first invocation until termination of whole program.
- Static does not make any sense in main().
- Function header vars, are always local e.g.:

void func2(int x) {
    int y;
    //Additional code goes here
}

- in case local and global variable with the same name: 
the program temporarily ignores the global variable, and continues to ignore it 
until the local variable goes out of scope.
- uninitilized local var: garbage
- uninitilized global var: 0
/*

/* 
Tip register:
If a particular variable can be kept in a register, manipulations
of the variable are much faster. 
- We kindly ask, and dont tell to keep a var in reg.
- Must be numeric, some platforms ignore it anyway. 
*/
void func3(void) {
    register int x;
    /* Additional code goes here */
}