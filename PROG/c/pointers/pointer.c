#include <stdio.h>

int main()
{
  int a;   
  int *p = NULL; 
  //var p pointing to type int                  
  //could have been declared
  
  printf("\n ---ILLUSTRATE POINTERS---\n");
  printf("\n Enter int a: ");
  scanf("%d", &a);
  //expect an int and stick it in address of a (which is &a)
  
  printf("\n 1.1. value of a, a:              %d", a);
  printf("\n 1.2. size of type(a):            %lu bytes\n-----", sizeof(a));
  
  printf("\n 2.1. addr of a, &a:              %p", &a);   
  printf("\n 2.2. size of type(&a):           %lu bytes", sizeof(&a));
  printf("\n 2.3. &a deref'ed, *&a:           %d", *&a);
   
  printf("\n\n----------\n take addr of a, make it value of p, (p=&a) :\n----------"); 
  p = &a;                       
  //Stores address of number in pointer

  printf("\n 3.1. value of pointer, p:          %p", p);  
  // Output the value (an address) 
  printf("\n 3.2. size of type(p):              %lu bytes", sizeof(p));
  // Output the size
  printf("\n 3.1. addr of pointer, &p:          %p", &p);
  // Output the address
  printf("\n 3.4. value pointed to, *p:         %d\n", *p);
  // Value at the address */
}


