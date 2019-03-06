#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*predicate_t)(const void *);

int odd(const void *input) {            //predicate function
 return *(int *)input & 1;
}

void filter(const void *base,           //newly built filter function
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

int main(int argc, char *argv[]) {
  int array[10] = {5, 2, 7, 3, 4, 1, 9, 8, 0, 6};
  int i;
  int *result;
  size_t result_size;

  filter(array,                         //calls filter with all parameters
         sizeof(int),
         10,
         (void *)&result,
         &result_size,
         odd);

  printf("Original:\n");
  for (i = 0; i < 10; i++) {
    printf("%d: %d\n", i, array[i]);
  }

  printf("Filtered:\n");
  for (i = 0; i < result_size; i++) {
    printf("%d: %d\n", i, result[i]);
  }
}