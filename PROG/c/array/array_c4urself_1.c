/*
basics on arrays
*/

#include <stdio.h>

int main (int argc, int *argv[]){
  
  int i, j;
  
	int twod_array[2][4]  = {{1,5,3},{21,34,45,68}}; 
	//2 dims with each 4 elements max
  
	char ch_array[6]       = "ArrayT";
  
  printf("--- Value ---------     --- Addresses --------\n\n");
  
  for (i = 0; i < 2; i++) {     //array has two dims   
    for (j = 0; j < 4; j++) {   //max number of elements in either
      //go through both loops, printing the array locations and their values 
      printf("twod_array[%d][%d] = %d", i, j, twod_array[i][j] );
      //on same line print array mem addresses
      printf("\t&twod_array[%d][%d] = %p\n", i, j, &twod_array[i][j] );  
    }
    printf(".\n");
  }
  printf("..\n");
  
  for (i = 0; i < 6; i++) {
    //go through loop, printing char array, ASCI code, and char  
    printf("ch_array[%d] = %x %c", i, ch_array[i], ch_array[i] );
    //on same line print array mem addresses
    printf("\t&ch_array[%d] = %p\n", i, &ch_array[i] );
  }
}

