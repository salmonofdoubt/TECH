#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  long arr[50];
  arr[49] = 123,456;
       
  int i;
  for (i = 1; i <= 100, i+= 3)
    ...;  
  
  int i = 1;
  while (i <=100)
    ...;
    i+= 3;
     
  
  return 0;
  //exit(EXIT_SUCCESS);
}



int get_1_or_2( void )
{
    int answer = 0;

    while( answer < 1 || answer > 2 )
    {
        printf(Enter 1 for Yes, 2 for No);
        scanf( "%f", answer );
    }
    return answer;
}