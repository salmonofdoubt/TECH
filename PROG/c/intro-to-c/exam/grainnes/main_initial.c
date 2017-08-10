#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <dirent.h>

#define CHUNKSIZE 1024
#define MAXNAMESIZE 256

// Implement find
// functions

void usage(const char *progname) {
  printf("Usage: %s <path to dir...>\n", progname);
  }


int main(int argc, char *argv[]) {
// variables
  DIR *dirp;                            // pointer to directory steam
  struct dirent *dirent;                // pointer to dirent which 

  char *filenames;
  int buffsize = CHUNKSIZE;
  int entries = 0;

  int i = 0;


  if (argc < 2) {                       // test for a specified directory
    usage(argv[0]);
  }

  if (chdir(argv[1]) == -1) {           // move to the path requested
    chdir(".");
  }

  dirp = opendir(".");                  // 
  if (dirp == NULL) {
    perror("opendir failed");
    exit(EXIT_FAILURE);
  }

  filenames = (char *) malloc(buffsize * MAXNAMESIZE);

  while ((dirent = readdir(dirp)) != NULL) {
    printf("%s\n", dirent->d_name);
    }
exit(EXIT_SUCCESS);
}
