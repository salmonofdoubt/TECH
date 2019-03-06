#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "find.h"
#include "predicates.h"

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s [options] [path...]\n", argv[0]);
  fprintf(stderr, "  [-n <name>]          - Match the filename\n");
  fprintf(stderr, "  [-o <owner uid>]     - Match the owner user ID\n");
  fprintf(stderr, "  [-g <group id>]      - Match the group ID\n");
  fprintf(stderr, "  [-t {p,c,d,b,f,l,s}] - Match the file type\n");
  fprintf(stderr, "  [-s <min filesize>]  - Match the minimum file size (in bytes)\n");
  fprintf(stderr, "  [-d <max depth>]     - Maximum recursion depth\n");
}

int main(int argc, char *argv[]) {
  /* Predicate function array to use
   * Default: none (print everything)
   */
  predicate_t pred[6] = {NULL};
  int npredicates = 0;
  int opt;

  opt_depth = -1;

  while ((opt = getopt(argc, argv, "n:o:g:t:s:d:")) != -1) {
    switch (opt) {
      case 'o':
        opt_uid = atoi(optarg);
        pred[npredicates] = pred_uid;
        npredicates++;
        break;
      case 'g':
        opt_gid = atoi(optarg);
        pred[npredicates] = pred_gid;
        npredicates++;
        break;
      case 'n':
        opt_name = optarg;
        pred[npredicates] = pred_name;
        npredicates++;
        break;
      case 't':
        switch (optarg[0]) {
          case 'p': opt_type = DT_FIFO; break;
          case 'c': opt_type = DT_CHR; break;
          case 'd': opt_type = DT_DIR; break;
          case 'b': opt_type = DT_BLK; break;
          case 'f': opt_type = DT_REG; break;
          case 'l': opt_type = DT_LNK; break;
          case 's': opt_type = DT_SOCK; break;
          default: usage(argc, argv); exit(EXIT_FAILURE);
        }
        pred[npredicates] = pred_type;
        npredicates++;
        break;
      case 'd':
        opt_depth = atoi(optarg);
        break;
      case 's':
        opt_min_size = atoi(optarg);
        pred[npredicates] = pred_min_size;
        npredicates++;
        break;
      default: /* '?' */
        usage(argc, argv);
        exit(EXIT_FAILURE);
    }
  }

  if (optind == argc) {
    find(".", pred, 0);
  } else {
    for (; optind < argc; optind++) {
      find(argv[optind], pred, 0);
    }
  }
  exit(EXIT_SUCCESS);
}
