#include <stdio.h>

//#define SOMETHING = 100

void copy(char x[], char y[]);

int main (int argc, char *argv[]){
  
  char string[] = "Hello!";
  char newstring[7];
  
  printf("\nBefore: %s", newstring);
  
  copy(string, newstring);          //newstring returned from "copy"
  printf("\nAfter : %s", newstring);
  
  return 0;
}

void copy(char x[], char y[]) {
  int i;
  
  for (i = 0; x[i] != '\0'; i++)
    y[i] = x[i];
    
  return;
}