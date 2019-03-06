#include <stdio.h>

typedef int i;
i w, y;             //clearly not really necessary, would be an aggregate data type

int main(void){
  printf("Enter weight (kg): ");
  scanf("%d", &);
  printf("Weight in grams: %d\n", weight(w));
  printf("Enter year of birth: ");
  scanf("%d", &y);
  printf("Age in year 2000 was: %d\n", year(y));
}

int weight(w){
  int w_grams;
  w_grams = w * 1000;
  return w_grams;
}

int year(y){
  int y_2000;
  y_2000 = y - 11;
  return y_2000;
}