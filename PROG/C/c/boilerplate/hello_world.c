/* Hello World program */ 

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int status;
  int i;
  char* bye = "Goodbye \0world!";
  status = printf("Hello\0 World!\n");
  printf("Value: %d\n", status);
  printf("%s\n", bye);
  for(i = 0; i < strlen(bye); i++) {
    printf("Part of a string (%d): %s\n", i, (bye + i));
  }
}
