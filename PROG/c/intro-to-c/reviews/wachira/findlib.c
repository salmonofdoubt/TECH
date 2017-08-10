#include <stdio.h>
#include <string.h>
#include "findlib.h"

int size_match(const void * file, const void * opt){
  const entry * e = (const entry *)file;
  const findopts * o = (const findopts *)opt;
  if(o->size == -1) return 1;
  if (e->size >= o->size) return 1;
  return 0;
}

int name_match(const void * file, const void * opt){
  const entry * e = (const entry *)file;
  const findopts * o = (const findopts *)opt;
  if(o->name == NULL) return 1;
  if (strcmp(e->name,o->name) == 0) return 2;
  return 0;
}


int uid_match(const void * file, const void * opt){
  const entry * e = (const entry *)file;
  const findopts * o = (const findopts *)opt;
  if(o->uid == -1) return 1;
  if (e->uid == o->uid) return 4;
  return 0;
}

int gid_match(const void * file, const void * opt){
  const entry * e = (const entry *)file;
  const findopts * o = (const findopts *)opt;
  if(o->gid == -1) return 1;
  if (e->gid == o->gid) return 8;
  return 0;
}

int type_match(const void * file, const void * opt){
  const entry * e = (const entry *)file;
  const findopts * o = (const findopts *)opt;
  if(o->type == NULL) return 1;
  if (strcmp(e->type, o->type) == 0) return 16;
  return 0;
}
