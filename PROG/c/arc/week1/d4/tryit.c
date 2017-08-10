#include <stdio.h>
int x,y;

int main(void){ 
  printf("\nEnter two numbers\n");
  scanf("%d %d" , &x, &y);
  printf("\n\n%d is bigger",(x>y)?x:y);
  return 0;
}