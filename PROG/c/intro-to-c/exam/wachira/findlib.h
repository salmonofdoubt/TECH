#ifndef FINDLIB_H
#define FINDLIB_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


typedef struct options_struct { 
  char * dirname; char * name; char * type;
  uid_t uid; gid_t gid; long size; int depth;
} findopts;

typedef struct directory_entry {
  char name[256]; long size;
  char type[2]; uid_t uid; gid_t gid;
} entry;

typedef int (*match_func)(const void *, const void *);

extern int size_match(const void *a, const void *b);
extern int name_match(const void *a, const void *b);
extern int uid_match(const void *a, const void *b);
extern int gid_match(const void *a, const void *b);
extern int type_match(const void *a, const void *b);

#endif
