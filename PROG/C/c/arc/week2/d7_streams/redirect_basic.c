/* 
redirection:
./exe > OUT.txt
with an existing input file: 
./exe < in.txt > out.txt
BASIC USAGE OF stdin and stdout
*/
 
#include <stdio.h>
 
int main(void) {
  char buf[80];
  
  gets(buf);
  printf("INFO: %s", buf);
  return 0;
}