#include <stdio.h>

//

int main ( int argc, char *argv[] ){
  struct sale {
     char customer[20];
     char item[20];
     float amount;
  } mysale = {"Acme Industries",
              "Left-handed widget",
              1000.00
              };
              
  printf("%s\n", mysale.customer);
  printf("%s\n", mysale.item);
  printf("%.2f\n", mysale.amount);
  
  return 0;
  //exit(EXIT_SUCCESS);
}