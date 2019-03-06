#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define CHUNKSIZE 1000
#define NAMESIZE 256

int main(int argc, char *argv[]) {
  DIR *dirp;
  struct dirent *dirent;
  struct stat sb;

  char *filenames;
  unsigned int buffsize = CHUNKSIZE;
  unsigned int entries = 0;

  unsigned int i = 0;

  if (argc < 2) {
    printf("Usage: %s <dir>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (chdir(argv[1]) == -1) {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  dirp = opendir(".");
  if (dirp == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  filenames = (char *) malloc(buffsize * NAMESIZE);

  while ((dirent = readdir(dirp)) != NULL) {
    printf("%s\n", dirent->d_name);

    if (stat(dirent->d_name, &sb) == -1) {
      printf("Failed to stat %s\n", dirent->d_name);
    }
    printf("I-node number:            %ld\n", (long) sb.st_ino);
    
    printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);
    
    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);
    
    printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);
    
    printf("Last status change:       %s",   ctime(&sb.st_ctime));
    printf("Last file access:         %s",   ctime(&sb.st_atime));
    printf("Last file modification:   %s\n", ctime(&sb.st_mtime));

  }

  exit(EXIT_SUCCESS);
}
