/* Declarating, using, and calling functions

void                square1       (void);
no return value    name       no input parameter

void                square2       (int i);
no return value    name       1 input parameter

int                 square3       (void);    
1 return value      name      no input parameter

int                 square4       (int i);   
1 return value      name      1 input parameter

int                 area          (int b, int h);
1 return value      name      2 input parameter
*/

#include <stdio.h>

// 1. Definitions of the functions

// Function that reads from standard input an integer, prints it together with its sum   
void square1(void){
  int x;

  printf("Please enter an integer > ");
  scanf("%d", &x);
  printf("The square of %d is %d\n", x, x*x);
}

// Function that prints i together with its sum
void square2(int i){
  printf("The square of %d is %d\n", i, i*i);
}  

// Function that reads from standard input an integer and returns its square
int square3(void){
  int x;
  printf("Please enter an integer > ");
  scanf("%d", &x);
  return (x*x);
}

// Function that returns the square of i
int square4(int i){
  return (i*i);
}

// Function that returns the area of the rectangle with base b and hight h
int area(int b, int h){
  return (b*h);
}


// 2. Main program: Using the various functions
int main (void) {
   square1();
   // Calling the square1 function 
   square2(7);   
   // Calling the square2 function using 7 as parameter corresponding to the formal parameter i
   
   printf("The value of square3() is %d\n", square3());
   // Using the square3 function
   printf("The value of square4(5) is %d\n", square4(5)); 
   // Using the square4 function with 5 as actual parameter corresponding to i
   printf("The value of area(3,7) is %d\n", area(3,7));
   // Using the area function with 3, 7 as actual parameters corresponding to b, h respectively
}


/* The output would be:
Please enter an integer > 3
The square of 3 is 9
The square of 7 is 49
Please enter an integer > 4
The value of square3() is 16
The value of square4(5) is 25
The value of area(3,7) is 21
*/