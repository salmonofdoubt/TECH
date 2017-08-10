#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CHUNK_SIZE 4096

int main(int argc, char *argv[]) {
  char *buffer = NULL;
  size_t buffer_size = 0;
  int offset = 0;
  int nread = 0;
  size_t write_size = 0;

  /* Extend the buffer if we need to and keep reading from stdin */
  do {
    offset += nread;
    /*  Note that this will run at least once, as the initial value of offset
     *  and buffer_size is zero
     */
    if (offset >= buffer_size) {
      buffer_size += CHUNK_SIZE;
      if ((buffer = realloc(buffer, buffer_size)) == NULL) {
        perror(argv[0]);
        exit(EXIT_FAILURE);
      }
    }
  } while ((nread = read(STDIN_FILENO, buffer + offset, buffer_size - offset)) > 0);

  if (nread < 0) {
    perror(argv[0]);
    exit(EXIT_FAILURE);
  }
  
  /* Iterate through the buffer starting from the last position down to the 
   * first position
   */
  for (offset = offset - 1; offset >= 0; offset--) {
    /* Increase the number of bytes we will have to write */
    write_size++;

    /*  If we hit the beginning of the buffer OR the previous character is a
     *  newline, print write_size bytes from the buffer starting from our
     *  current position. Also, reset the number of bytes to be written.
     */
    if (offset == 0 || buffer[offset - 1] == '\n') {
      write(STDOUT_FILENO, buffer + offset, write_size);
      write_size = 0;
    }
  }

  exit(EXIT_SUCCESS);
}
