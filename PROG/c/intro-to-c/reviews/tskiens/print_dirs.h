/* file : print_dirs.h */

// leczb: the symbol name you use in the #ifndef guard should match the
//        filename. This shoud be
//          #ifndef PRINT_DIRS_H
//          #define PRINT_DIRS_H 1
#ifndef FIND_H
#define FIND_H 1

// leczb: This is not correct: you are including this file recursively.
#include "print_dirs.h"

// leczb: Minor comment: function declarations in header files should have the
//        "extern" qualifier.
//        Minor comment: it's best practice to declare input-only pointer arguments
//                       using the const qualifier. This would be:
//                         extern int print_usage(const char *my_progname);
//                
int print_usage(char *my_progname);

// leczb: input should be declared as const char *input
int not_dot(const void *input);

void print_dir(char *p);

#endif
