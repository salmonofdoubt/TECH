#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 4096

int main(int argc, char* argv[]) {
  FILE* haystack;
  char* current_line;
  current_line = (char*) malloc(LINE_SIZE);
  // First, make sure all arguments are present
  if (argc < 3) {
    puts("Usage: grep <searchstring> filename");
    exit(EXIT_FAILURE);
  }
  const char* needle   = argv[1];
  const char* filename = argv[2];
  // Second, try to open the file
  if ((haystack = fopen(filename, "r")) != NULL) {
    while(fgets(current_line, LINE_SIZE, haystack) != NULL) {
      if (strstr(current_line, needle) != NULL)
        printf("%s", current_line);
    }
    fclose(haystack);
    exit(EXIT_SUCCESS);
  }
  else {
    puts("Sorry, could not open the file");
    exit(EXIT_FAILURE);
  }
}
  