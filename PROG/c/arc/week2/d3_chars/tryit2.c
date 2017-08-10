#include <stdio.h>

//#define SOMETHING = 100

int count(char x[], char y[]);

int main (int argc, char *argv[]){
  
  char astr[] = "Hello!";
  char bstr[] = " Lovely World";
  int res;
  
  res = count (astr, bstr);
  printf("\nLonger string is %d characters.", res);
  
  return 0;
}

int count(char x[], char y[]) {
  int i, j;
  
  for (i = 0; x[i] != '\0'; i++){
  }
  for (j = 0; y[j] != '\0'; j++){
  }
    
  return (i > j ? i : j);  //is i > j? If so, return i, else
}