#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int filter_beginning(const char* filename, const char* filter) {
	return(strncmp(filter, filename, strlen(filter)) == 0);
}

int filter_end(const char* filename, const char* filter) {
	return(strncmp(filter, filename + strlen(filename) - strlen(filter), strlen(filter)) == 0);
}

void listdir(const char* path, int(*filter_function)(const char*, const char*), const char* filter_arg) {
  DIR *dir;
  struct dirent* dirent;

  dir = opendir(path);
  if (dir == NULL) {
	perror("listdir");
	exit(EXIT_FAILURE);
  }
  
  while ((dirent = readdir(dir)) != NULL) {
    if (filter_function(dirent->d_name, filter_arg))
        printf("%s\n", dirent->d_name);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
	printf("Usage: %s <filter> <dir>\n", argv[0]);
	exit(EXIT_FAILURE);
  }
  
  if (argv[1][0] == '*') {
        // filter based on the end
  	listdir(argv[2], filter_end, argv[1]+1);
  }
  else if (argv[1][strlen(argv[1]) -1] == '*') {
        // filter based on the beginning
        argv[1][strlen(argv[1]) -1] = '\0';
  	listdir(argv[2], filter_beginning, argv[1]);
  }
  else {
 	printf("invalid filter");
        exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
