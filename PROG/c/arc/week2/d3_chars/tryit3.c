#include <stdio.h>
#include <stdlib.h>


//#define SOMETHING = 100
char * makememory(char x[], char y[]);
void cat(char x[], char y[], char catresult[]);


int main (int argc, char *argv[]){
  
  char astr[] = "Hello";
  char bstr[] = " Lovely World!";

  printf("\nConcatenated strings: \n%s", makememory(astr, bstr));
  return 0;
}

char * makememory(char x[], char y[]){
  char *res;
  int i, j;
  
  for (i = 0; x[i] != '\0'; i++)
    ;
  for (j = 0; y[j] != '\0'; j++)
    ;
    
  if ((res = (char *) malloc(sizeof(char)* (i + j + 1))) == NULL ) {
    printf("Not enough memory to allocate buffer\n");
    exit(1);
  }
  cat(x, y, res);
  return(res);
}
  


void cat(char x[], char y[], char catresult[]) {
   
  int i, j;
  
  for (i = 0; x[i] != '\0'; i++){
    catresult[i] = x[i];
  }
  for (j = 0; y[j] != '\0'; i++, j++){
    catresult[i] = y[j];
  }

  return;   
}
    