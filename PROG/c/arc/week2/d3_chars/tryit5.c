/* EXER1012.C Day 10 Exercise 12 */  
/* MS-DOS Application */
/* Print an ASCII box on the screen */

#include <stdio.h>

int ulcorner = 201;
int urcorner = 187;
int llcorner = 200;
int lrcorner = 188;
int horizont = 205;
int vertical = 186; 
int count;

int main(void)  {

/* Print top line of box. */
  printf("%c", ulcorner);
  for (count = 0; count < 15; count++)
    printf("%c", horizont);
  printf("%c\n", urcorner);

/* Print sides of box. */
  for (count = 0; count < 10; count++)  {
    printf("%c", vertical); 
    printf("               ");
    printf("%c\n", vertical);
  }

/* Print bottom line of box. */
  printf("%c", llcorner);
  for (count = 0; count < 15; count++)
    printf("%c", horizont);
  printf("%c\n", lrcorner);

  return 0;
}