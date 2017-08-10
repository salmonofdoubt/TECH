#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  
  int i;
  
  for (i = 0; i < argc; ++i) {
    printf( "Argument #%d has %d characters -> '%s'\n",
    (i + 1), my_strlen(argv[i]), argv[i] );
    //1st argv, calls my_strlen
  }
}

int my_strlen(char* string) {
  
  int pointer = 0;
  
  while (string[pointer]) pointer++;
  return pointer;
}

