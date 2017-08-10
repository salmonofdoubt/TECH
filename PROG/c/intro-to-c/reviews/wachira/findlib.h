#ifndef FINDLIB_H
// leczb: Minor: it should be
//          #define FINDLIB_H 1
#define FINDLIB_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


// leczb: Style: you should list the fields on separate lines.
typedef struct options_struct { 
  char * dirname; char * name; char * type;
  // leczb: size should be off_t or size_t
  uid_t uid; gid_t gid; long size; int depth;
} findopts;

typedef struct directory_entry {
  char name[256]; long size;
  // leczb: type should be unsigned char if you use the struct
  //        returned by readdir() or mode_t if you use stat()
  char type[2]; uid_t uid; gid_t gid;
} entry;

// leczb: This could be
//          typedef int (*mathc_func)(const entry*, const findopts *)
//        ...then you don't need to sprinkle casts everywhere.
typedef int (*match_func)(const void *, const void *);

extern int size_match(const void *a, const void *b);
extern int name_match(const void *a, const void *b);
extern int uid_match(const void *a, const void *b);
extern int gid_match(const void *a, const void *b);
extern int type_match(const void *a, const void *b);

#endif
