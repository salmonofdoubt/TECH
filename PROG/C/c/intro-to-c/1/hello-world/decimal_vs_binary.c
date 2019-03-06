#include <stdio.h>
#include <stdlib.h>

#define ANOTHERCONST 123.43

int main(int argc, char *argv[]) {
  float f = 0.0;
  int i = 0;
  const float myconst = 12.3;

  for (i = 0; i < 100; i++) {
    printf("%4d: %7.4f\n, %f", i, f, ANOTHERCONST);
    f += 1/10.0;
  }

  *(int *)(0x22f9002) = 5;

  exit(EXIT_SUCCESS);
}
