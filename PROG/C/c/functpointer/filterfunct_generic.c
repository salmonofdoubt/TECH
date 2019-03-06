#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// implement a generic filter function
// typedef int (*predicate_t)(const void *)
//todo: seperate headers, stick filter fct into filter.h
//complile to .o, then merge different o. files to see if it works 
//all signatures of functions that others may want to use


//------At least one testfunction
typedef int (*predicate_t)(const void *);

int predicate_function(const void* a) {
  return *((int *)a) >= 0;           //int value of a, casted from void
// if true, return
}

void filter(void *a, size_t member_size, size_t nmemb,
            void ** out_data, size_t *out_nmemb,
            predicate_t predicate ){
              *out_data = malloc(member_size * nmemb);
              int counter = 0;
              int count = 0;
              for(; counter < nmemb; counter++ ){
                if(predicate( a+counter*member_size )){
                  memcpy(*out_data + count*member_size ,
                   a + counter*member_size , member_size);
                  count++;
                }
              }
              *out_nmemb = count;
}

//-------Main, calls the filter function with test function

int main(int argc, int *argv[]) {
  int a[10] = {1,-2,3,-4,5,6,-7,8,9,-10};       //input array
  int *out_data = NULL;                             //output array, needs to be malloc'ed? 
  int i;
  size_t nmemb = 10;
  int out_nmemb = 10;
  //print (hardcoded) input array
  for (i=0; i<10; i++) { 
    printf("Initial array: %d\n", a[i]);        //print the ith element
  }
  //TODO: call the filter function, passing all values, might be addresses
  filter((void *)a, sizeof(int), nmemb,
          (void**) &out_data, (void *)&out_nmemb, predicate_function);
          
        i = 0;
        for(; i < out_nmemb ; i++){
          printf("out_data[%d] = %d\n",i, out_data[i]);
        }
  
  /* test predicate
  int neg = 1;
  printf("%d\n", predicate_function((void *)&neg));
  */
  return 0;             
}
