/* 
stdin, stdout, stderr */

#include <stdio.h>
#include <extkey.h>
 
int ext_key(void);
 
int main(void) {
  int ch;
  
  puts("Press any extended key; "
       "press F1 to exit.");
  
  while (1) {
    ch = ext_key();
    if (ch == 59)    /* F1? */
      break;
    else
      printf("\nThat key's code has a value of "
             "%d.", ch);
  }
  return 0;
}
 
int ext_key(void) {
  int ch;
  
  /* Wait until a zero byte comes in. */
  
  while ((ch = getch()) != 0)
    ;
    
  /* Return the next character. */
  
  return getch();
}