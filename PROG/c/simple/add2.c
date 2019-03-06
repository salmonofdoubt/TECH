//add two input numbers
#include <stdio.h>

int main(int argc, char *argv[]) {
  int a, b;
  printf("Enter two Integers:\n");
  scanf("%d %d", &a, &b);
  printf("Integers entered: %d %d\n", a, b);
  printf("The sum is:       %d\n",a + b);
}