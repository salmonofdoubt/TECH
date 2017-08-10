#include <stdio.h>

//#define SOMETHING = 100

//fct prototypes go here

int main ( int argc, char *argv[] ){
  
  char *char_ptr;
  
  //----
  
  int cost = 100, x   ;
  int *p_cost         ;
  p_cost = &cost      ;
  
  x = cost            ;
  x = *p_cost         ;
  
  printf("\nValue of pointer:       %d", p_cost)  ;  //address
  printf("\nValue being pointed to: %d", *p_cost) ;  //value
  
  //----
  
  float radius;
  int *p_radius = &radius;
  
  //-----
  
  int data[4];
  data[3]     = 100;
  *(data + 2) = 100;
  
  
  //testing sumarrays----
  int data1[3] = {1,2,3};
  int data2[3] = {4,5,6};
  int added[6];
  int resulting[6];
  printf("\n\nsumarrays returns: %d", sumarrays(data1,3,data2,3));
  
  //testing addarrays----
  resulting = addarrays(data1, data2, added, 3);
  printf("%d", resulting);
  
  return 0;
}

int sumarrays(int x[], int x_len,   int y[], int y_len){
  int tot = 0, tot1 = 0, tot2 = 0;
  int i;
  
  for (i = 0; i < x_len; i++)
    tot1 = tot + x[i];
    
  for (i = 0; i < x_len; i++)
    tot2 = tot + y[i];         
  
  return tot1 + tot2;         
}


int addarrays(int x[], int y[], int added[], int len){
  int i;
  
  for (i = 0; i < len; i++)
    added[i] = x[i] + y[i];

  return;         
}














