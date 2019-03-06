#include <stdio.h>

#define PI 3.14159              // symbolic constant
const double pi = 3.14159;       // could also be defined with 'const', but precision issue... 
                                // note that PI, pi or Pi are all different things                      

typedef int i;
i radius, area;             //clearly not really necessary, would be an aggregate data type

int main(void){
  printf("Enter radius (i.e. 10): ");
  scanf("%d", &radius);
  area = pi * radius * radius;
  printf("\n\nArea = %d", area);
  return 0;
}
