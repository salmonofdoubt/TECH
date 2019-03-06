#ifndef VISIT_H
#define VISIT_H 1
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define CHUNKSIZE 1024
#define MAXNAMESIZE 256

void visit(const char *directory);
#endif
