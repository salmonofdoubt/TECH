//write new file

#include <stdio.h>
#include <stdlib.h>

int main() { 
  FILE *file; 
  file = fopen("file.txt","a+"); 
  //if new file, starts at BOF a file or create a file if it does not exist.
  fprintf(file,"%s","This is just an example :)"); /*writes*/ 
  fclose(file); /*done!*/ 
  getchar(); /* pause and wait for key */ 
  return 0; 
}