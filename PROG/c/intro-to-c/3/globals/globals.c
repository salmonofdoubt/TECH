/* What makes this global?*/

#include <stdio.h>

int main(int argc, char *argv[]) {
 int array[100];

 int size;

 size = &array[1] - &array[0];
 
 printf("%d\n", size);
}
