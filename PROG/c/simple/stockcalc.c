/*testing types*/
#include <stdio.h>

#define STOCK 100     
#define MAX 40
//global constants valid anywhere in program

int main(int argc, char *argv[]) {
  int       num_wanted;
  double    cost;
  int       num_stock = STOCK;
  //sets int num_stock to global const 'STOCK'     
  printf("Num: ");
  scanf("%d", &num_wanted);             
  //ex
  pect an int, stick into ***addr*** of num
  //
  if (num_wanted>100) {
    printf("Only 100 left");
  }
  else if (num_wanted<0) {
    printf("negative");
  }
  else {
    cost = 0.50 * num_wanted;
    //do some math        
    printf("num_wanted: %.4d\namount: €%.2f\n", num_wanted, cost);
    // 1st%: .4d: print 'num as 4 dec, padding with 0
    // 2nd%: .2:  print cost' as float with 2 comma digits 
  }
}
