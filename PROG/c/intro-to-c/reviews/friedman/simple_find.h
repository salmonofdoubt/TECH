#ifndef SIMPLE_FIND_H
// leczb: Minor: missing define value. Should be
//          #define SIMPLE_FIND_H 1
#define SIMPLE_FIND_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

struct operations {
  char * match;
  char * type;
  int * max_depth;
};

// leczb: Minor: functions declared in the header file should have the "extern"
//        qualifier.
int scandir_filter(const struct dirent * name);

int name_matching(const char * name, const unsigned char * type,
                  const char * match);

int type_matching(const struct dirent * name, const char * type);

void find(const char * path, const struct operations * ops);
#endif
