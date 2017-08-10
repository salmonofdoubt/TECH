// A pointer is a var which contains the ADDRESS of another variable
#include <stdio.h>

//fct prototypes go here

int main ( int argc, char *argv[] ){

int rate; 
int *p_rate;    //  * so to make it a pointer
                //  p_.. is just for readability

rate = 10;      //  initialize rate
p_rate = &rate; //  initialize the pointer too!
                //  assigns the address of rate to p_rate 
                //  so p_rate is now an initialized pointer :)

printf("rate: %d\n", rate);       //should print value of rate
printf("p_rate: %d\n", *p_rate);  //should print value of rate

return 0;
//exit(EXIT_SUCCESS);
}


