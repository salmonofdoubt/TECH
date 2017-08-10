#include <stdio.h>

typedef int i;

i radius, area;

int main(void){
  printf("Enter radius (i.e. 10): ");
  scanf("%d", &radius);
  area = 3.14159 * radius * radius;
  printf("\n\nArea = %d", area);
  return 0;
}
