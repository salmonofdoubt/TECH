#ifndef FILTER_H
#define FILTER_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*predicate_t)(const void *);

void filter(const void *base,
            size_t member_size,
            size_t nmemb,
            void **out_data,
            size_t *out_nmemb,
            predicate_t pred);

#endif
