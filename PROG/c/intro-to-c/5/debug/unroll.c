#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < 10; i++) {
    printf("%d\n", i);
  }

  const char *p = "abcdef";

  printf("%c\n", 2[p]);
  exit(EXIT_SUCCESS);
}
