#include <stdio.h>

struct x { 												/* Declare the structure.	*/
	int a;
	int b;
	int c;
} ;

void function(struct x * );				/* Declare any prototypes used */


int main() {  
	
	struct x z, *ptrz;							/* make struct a var (z, and *ptrz) */

  ptrz = &z;											/* init: put the address of 'z' into 'pz' */
  z.a = 3;												/* init z.a, z.b    */
	z.b = 7;

  printf("a before fct call: %d \n", ptrz->a);

  function(ptrz);
	
	printf("a after fct call: %d or %d or %d \n", ptrz->a, (*ptrz).a, z.a);

	return 0;
}

void function(struct x *ptrz) { 
	/* show 'z.a' by ref'ing pointer 'ptrz', which holds addr of 'z' */
  printf("a insider funct using ptr: %d \n", ptrz->a);
}
