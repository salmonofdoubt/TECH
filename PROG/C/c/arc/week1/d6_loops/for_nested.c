/* LIST0602.c: Day 6 Listing 6.2 */
/* Demonstrates nesting two for statements */
 
#include <stdio.h>
 
void draw_box(int row, int column);
 
int main(void) {
  int a, b;
  printf("Enter dimensions: \n");
  scanf("%d%d", &a, &b);
  draw_box(a, b);
  return 0;
}
 
void draw_box(int row, int column) {
  int i, j;
  for(j = row; j > 0; j--) {
    for(i = column; i > 0; i--)
      printf("X");
     printf("\n");
  }
}