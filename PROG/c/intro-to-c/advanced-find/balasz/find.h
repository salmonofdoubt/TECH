#ifndef FIND_H
#define FIND_H 1

#include <dirent.h>

int opt_depth;

typedef int (*predicate_t)(const char *, const struct dirent *);

extern void find(const char *path, predicate_t *filter_chain, int depth);

#endif
