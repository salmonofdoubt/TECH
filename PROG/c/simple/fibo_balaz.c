#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursive(int i) {
  if (i <= 0) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return fibonacci_recursive(i - 1) + fibonacci_recursive(i - 2);
}

double phi;
double sqrt5;

int fibonacci_closed(int n) {
  return ((pow(phi, n) - pow(1.0 - phi, n)) / sqrt5) ;
}

int main(int argc, char *argv[]) {
  int i;
  while (scanf("%d", &i) != EOF) {
    sqrt5 = sqrt(5.0);
    phi = (1.0 + sqrt5) / 2.0;
    printf("%d %d\n", i, fibonacci_closed(i));
  }
  exit(EXIT_SUCCESS);
}
