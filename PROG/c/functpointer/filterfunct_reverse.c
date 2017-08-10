//
/*void qsort( void *a[0],     //pointer to first element
              size_t nmember, //number of numbers
              size_t size,    //
              int (*compar)(const void*, const void*)
              )
  */
  
  //use qsort to reverse      
  
  
#include <stdlib.h>
#include <stdio.h>

int reverse(const void* a, const void* b){
  const int *aa = (int*)a;  //casting into int pointer necessary as qsort takes void
  const int *bb = (int*)b;

  if (*aa > *bb) {          //using the actual integers 
    return 1;
    }
  if (*bb > *aa) {
    return -1;
    }
  if (*aa == *bb) {
    return 0;
    }
}

int main(int argc, int *argv[]) {
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int i;
  
  for (i=0; i<10; i++) { 
    printf("Initial array: %d\n", a[i]);
  }
  
  size_t nmember = 10;
  size_t size = sizeof(int*);
  qsort(a,          //pointer to first element
        nmember,    //number of numbers
        size,       //
        reverse);    //as per man, 4th parameter is my function 
              
  for (i=0; i<10; i++) { 
    printf("Initial array: %d\n", a[i]);
    
  }
  return 0;             
}



 



