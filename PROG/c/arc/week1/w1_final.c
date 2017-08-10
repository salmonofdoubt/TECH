/* Program: week1.c                              */
/* A program to enter the ages and incomes of up */
/* to 100 people.  The program prints a report   */
/* based on the numbers entered.                 */
/* MS-DOS Application */
 
/* Included files. */
 
#include <stdio.h>
 
/* Defined constants. */
 
#define MAX 100
#define YES 1
#define NO  0
 
/* Variables. */
 
long income[MAX];        /* To hold incomes.     */
int  month[MAX], day[MAX], year[MAX];
                         /* To hold birthdays.   */
int   x, y, ctr;         /* For counters.        */
int   cont;              /* For program control. */
long month_total, grand_total; /* For totals.    */
 
/* Function prototypes. */
 
int display_instructions(void);
void get_data(void);
void display_report(void);
int continue_function(void);
 
/* Start of program. */
 
int main(void) {
  cont = display_instructions();
  
  if (cont == YES) {
    get_data();
    display_report();
  }
  else
    printf("\nProgram Aborted by User!\n\n");
  return 0;
}
/* Function: display_instructions()             */
/* Purpose: This function displays information  */
/* on how to use this program and asks the user */
/* to enter 0 to quit, or 1 to continue.        */
/* Returns: NO - if the user enters 0           */
/* YES - if user enters any number other than 0 */
 
int display_instructions(void) {
  printf("\n\n");
  printf("\nThis program enables you to enter up"
         " to 99 people\'s");
  printf("\nincomes and birthdays. It then prints"
         " the incomes by");
  printf("\nmonth along with the overall income"
         " and overall average.");
  printf("\n");
  
  cont = continue_function();
  
  return(cont);
}
 
/* Function: get_data()                          */
/* Purpose: This function gets the data from the */
/* user. It continues to get data until either   */
/* 100 people are entered, or until the user     */
/* enters 0 for the month.                       */
/* Returns: Nothing                              */
/* Notes:   This allows 0/0/0/ to be entered for */
/* birthdays in case the user is unsure. It also */
/* allows for 31 days in each month.             */
 
void get_data(void) {
  for (ctr = 0; ctr < MAX && cont == YES; ctr++) {
    printf("\nEnter information for Person %d.",
           ctr + 1);
    printf("\n\tEnter Birthday:");
 
    do {
      printf("\n\tMonth (0-12): ");
      scanf("%d", &month[ctr]);
    } while (month[ctr] < 0 || month[ctr] > 12);
 
    do {
      printf("\n\tDay (0-31): ");
      scanf("%d", &day[ctr]);
    } while (day[ctr] < 0 || day[ctr] > 31);
 
    do {
      printf("\n\tYear (0-1999): ");
      scanf("%d", &year[ctr]);
    } while (year[ctr] < 0 || year[ctr] > 1999);
 
    printf("\nEnter Yearly Income (whole $s): ");
    scanf("%ld", &income[ctr]);
 
    cont = continue_function();
  }  
}
/* ctr equals number of people entered. */
 
/* Function: display_report()                   */
/* Purpose: This function displays a report to  */
/* the screen. Returns: Nothing                 */
/* Notes: More information could be displayed.  */
 
void display_report(void) {
  grand_total = 0;
  printf("\n\n\n");
  printf("\n         SALARY SUMMARY");
  printf("\n         ==============");
  
  for (x = 0; x <= 12; x++) {
    /* For each month, including 0 */
    month_total = 0;
    for (y = 0; y < ctr; y++) {
      if (month[y] == x)
        month_total += income[y];
    }
    printf("\nTotal for month %d is %ld", x, 
           month_total);
    grand_total += month_total;
  }
  printf("\n\nReport totals:");
  printf("\nTotal Income is %ld", grand_total);
  printf("\nAverage Income is %ld",
         grand_total/ctr);
 
  printf("\n\n* * * End of Report * * *");
}
 
/* Function: continue_function()                 */
/* Purpose: This function asks if user wants to  */
/* continue. Returns: YES - if user wants to     */
/* continue, NO - if user wants to quit          */
 
int continue_function(void) {
  printf("\n\nDo you wish to continue? "
         "(0=NO/1=YES): ");
  scanf("%d", &x);
  
  while (x < 0 || x > 1) {
    printf("\n%d is invalid!", x);
    printf("\nPlease enter 0 to Quit or "
           "1 to Continue: ");
    scanf("%d", &x);
  }
  if (x == 0)
    return(NO);
  else
    return(YES);
}