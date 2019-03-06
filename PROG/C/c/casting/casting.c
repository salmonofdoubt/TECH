//Typecasting is making a variable of one type, such as an int, act like another type, a char, for one single operation.

#include <stdio.h>

void alphabet(void){
  int x;
  
  for(x = 97; x <= 122; x++)  //97 is the ASCII code of ‘a’
    printf("%c", (char)x);    //Explicit casting from int to char
    printf("\n");
  
  for(x = 0; x <= 128; x++)
    printf("%c", x);          //Implicit casting from int to char thanks to %c
    printf("\n");
}

void floats(void){ 
  
  int a = 7, b = 5;
  float c;
    
  c = a / b;
  printf("7/5 is 1.4, getting: %f", c);
  printf("\n");
  
  c = (float)a / (float)b;
  printf("7/5 is 1.4, getting: %f", c);
  printf("\n");
}


int main(int argc, int *argv[]){
  
  alphabet();
  floats();
}

            
            