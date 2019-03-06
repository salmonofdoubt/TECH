#ifndef FIND_H
#define FIND_H 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_DIR "."
#define BUFFSIZE 1024

void PrintEntry(struct dirent *dirent, char *filename, const char *name,
                const int type, const int uid, const int gid, const int size);

void ReadDir(DIR *dp, char *dir, const char depth_set, char depthc,
             const char depth, const char *name, const int type,
             const int uid, const int gid, const int size);

void Find(int dir_count, char **dirs, const char depth_set, char depthc,
          const char depth, const char *name, const int type, const int uid,
          const int gid, const int size);
#endif
