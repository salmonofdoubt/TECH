/* LIST1501.c: Day 15 Listing 15.1 *
/* Demonstrates pointers and multidimensional */
/* arrays. */

#include <stdio.h>

int multi[2][4];

int main(void) {
	/* The array multi contains two arrays, each of which contains four integers.
	 Each integer requires four bytes of storage. With a total of eight integers,
	 the size of 32 bytes makes sense.*/
  printf("\nmulti = %u, sizeofmulti = %u", multi, sizeof(multi));
	/* multi[0] is an array containing four integers. Each integer takes four bytes
	   so the size of sixteen bytes for multi[0] also makes sense. */
  printf("\nmulti[0] = %u, sizeofmulti[0] = %u", multi[0], sizeof(multi[0]));
	/* Finally, multi[0][0] is an integer; so its size is, of course, four bytes.*/
  printf("\n&multi[0][0] = %u, sizeofmulti[0][0] = %u", &multi[0][0], sizeof(multi[0][0]));
  return 0;
}