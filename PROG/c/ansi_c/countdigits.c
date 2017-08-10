#include <stdio.h>
/* count digits, white space, others */

void B(){
   
  int inputchar, i, whitespace, otherchar;
  
  int digits[10];
  int matrix[10] = {0,1,3,4,5,6,7,8,9};

  whitespace = 0;
  otherchar = 0;

  for (i = 0; i < 10; ++i)
    digits[i] = 0;                              /* initialization */
      
  while ((inputchar = getchar()) != EOF)
    if (inputchar >= '0' && inputchar <= '9')   /* if char is digit ... */ 
    ++digits[inputchar - '0'];                  /* ... its numeric value is 0 */
  else if (inputchar == ' ' || inputchar == '\n' || inputchar == '\t')
    ++whitespace;
  else  
    ++otherchar;
  
  printf("Matrix = ");  
  for (i = 0; i < 10; ++i)
    printf(" %d", matrix[i]);
    
  printf("\nDigits = ");
  for (i = 0; i < 10; ++i)
    printf(" %d", digits[i]);
  
  printf(", whitespace = %d, otherchars = %d\n",
  whitespace, otherchar);
}
  


int main() {
  B();
}
