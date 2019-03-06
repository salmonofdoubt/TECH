/* LIST0402.c: Day 4 Listing 4.2 */
/* Illustrates the modulus operator. */
/* Inputs a number of seconds, and converts to */
/* hours, minutes, and seconds. */
 
#include <stdio.h>
 
#define SECS_PER_MIN 60    /* Define constants. */
#define SECS_PER_HOUR 3600
 
unsigned seconds, minutes, hours;
unsigned secs_left, mins_left;
 
int main(void) {
  /* Input the number of seconds. */
 
  printf("Enter number of seconds (<65000): ");
  scanf("%d", &seconds);
  
  hours = seconds / SECS_PER_HOUR;
  minutes = seconds / SECS_PER_MIN;
  mins_left = minutes % SECS_PER_MIN;
  secs_left = seconds % SECS_PER_MIN;
  
  printf("%u seconds is equal to ", seconds);
  printf("%u h, %u m, and %u s",
          hours, mins_left, secs_left);
  return 0;
}