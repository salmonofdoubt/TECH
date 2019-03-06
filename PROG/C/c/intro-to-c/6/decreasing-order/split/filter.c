#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filter.h"

void filter(const void *base,
            size_t member_size,
            size_t nmemb,
            void **out_data,
            size_t *out_nmemb,
            predicate_t pred) {
  void *output = malloc(nmemb * member_size);
  int i, j;

  for (i = 0, j = 0; i < nmemb; i++) {
    if (pred(base + i * member_size)) {
      memcpy(output + j * member_size,
             base + i * member_size,
             member_size);
      j++;
    }
  }

  *out_data = output;
  *out_nmemb = j;
}
