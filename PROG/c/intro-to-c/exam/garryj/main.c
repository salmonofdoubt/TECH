#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "find.h"

#define VERSION "1.1"

void PrintUsage(char *cmd_name){
  fprintf(stderr, "Usage %s [-n <name>] [-t c] [-u uid] [-o gid]\n", cmd_name);
  fprintf(stderr, "              [-d depth] <directory(s)>\n");
  exit(EXIT_FAILURE);
}

int GetTypeFromArg(char *optarg){
  int type = 0;
  if (strcmp("i", optarg) == 0) return DT_LNK;
  if (strcmp("d", optarg) == 0) return DT_DIR;
  if (strcmp("f", optarg) == 0) return DT_REG;
  if (strcmp("c", optarg) == 0) return DT_CHR;
  if (strcmp("b", optarg) == 0) return DT_BLK;
  if (strcmp("s", optarg) == 0) return DT_SOCK;
  return type;
}

int main(int argc, char *argv[]){
  int dir_count, i, opt;
  char * dirs[argc];
  char * name;
  int type;
  name = NULL;
  char depth_set = 0;
  char depth = 0;
  char depthc = 0;
  int uid = 0;
  int gid = 0;
  int size = 0;

  while((opt = getopt(argc, argv, "d:ho:n:s:t:u:v")) != -1) {
    switch (opt) {
      case 'd':
        depth_set = 1;
        depth = atoi(optarg);
        break;
      case 'h':
        PrintUsage(argv[0]);
        break;
      case 'o':
        gid = atoi(optarg);
        break;
      case 'n':
        name = optarg;
        break;
      case 's':
        size = atoi(optarg);
        break;
      case 't':
        type = GetTypeFromArg(optarg);
        break;
      case 'u':
        uid = atoi(optarg);
        break;
      case 'v':
        printf("Version: %s\n", VERSION);
        exit(EXIT_SUCCESS);
    }
  }

  if (argc > optind){
    for (i=optind; i<argc; i++, dir_count++){
      dirs[dir_count] = argv[i];
    }
  }
  else {
    dirs[0] = DEFAULT_DIR;
    dir_count = 1;
  }

  Find(dir_count, dirs, depth_set, depthc, depth, name, type, uid, gid, size);
 
  return(EXIT_SUCCESS);
}
