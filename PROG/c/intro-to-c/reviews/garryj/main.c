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

// leczb: Minor nitpick: cmd_name should be const char *
void PrintUsage(char *cmd_name){
  fprintf(stderr, "Usage %s [-n <name>] [-t c] [-u uid] [-o gid]\n", cmd_name);
  fprintf(stderr, "              [-d depth] <directory(s)>\n");
  exit(EXIT_FAILURE);
}

// leczb: Minor nitpick: the return type of this function should be unsigned
//        char (see the type of dt_dir on man 3 readdir)
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
  // leczb: Tbis is a new feature. See output from gcc with -pedantic
  //        Still valid though.
  char * dirs[argc];
  char * name;
  int type;
  name = NULL;
  char depth_set = 0;
  char depth = 0;
  char depthc = 0;
  // leczb: should be uid_t, int is signed and you'll get weird negative values
  //        for users with very high uid (where the MSB is 1)
  int uid = 0;
  // leczb: ditto: should be gid_t
  int gid = 0;
  // leczb: should be size_t
  int size = 0;

  while((opt = getopt(argc, argv, "d:ho:n:s:t:u:v")) != -1) {
    switch (opt) {
      case 'd':
        depth_set = 1;
        // leczb: FYI: atoi() fails silently, if the user provides invalid input
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
      // leczb: nice touch! :)
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
 
  // leczb: Nitpick: should be exit() instead of return
  return(EXIT_SUCCESS);
}
