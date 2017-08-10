#include <stdio.h>
#include <stdlib.h>

char string1[] = "Hello";
char string2[] = " Lovely World!";

char * mem(char a[], char b[]);  
void copychar(char a[], char b[], char c[]);

int main(void)  {

  printf("Concatenated string: %s", mem(string1, string2));
  return 0;
}

char * mem(char a[], char b[])  {

  char *newstr;
  int i, j;
  
  for (i = 0; a[i] != '\0'; i++)
    ;
  for (j = 0; b[j] != '\0'; j++)
    ;

  if ((newstr = (char *) malloc(sizeof(char)*
     (i + j + 1)))== NULL) {
    printf("Not enough memory to allocate buffer\n");
    exit(1);
  }
  
  copychar(a, b, newstr);
  return(newstr);

}

void copychar(char array1[], char array2[], char outarray[])  {

  int i, j;
  
  for (i = 0; array1[i] != '\0'; i++)
    outarray[i] = array1[i];
       
  for (j = 0; array2[j] != '\0'; i++, j++)
    outarray[i] = array2[j];

  return;
}