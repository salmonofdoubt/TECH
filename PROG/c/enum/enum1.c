//use of enum
//Printing for each day of the week, today, yesterday, and tomorrow, both as a string and as a number.
#include <stdio.h>

//---declarations
enum days {monday,tuesday,wednesday,thursday,friday,saturday,sunday};
typedef enum days days;
// This allows us to use "days" as an abbreviation for "enum days"

// Two useful functions 
  days yesterday(days today){
  return (today+6)%7;
  }
  days tomorrow(days today){
  return (today+1)%7;
  }

// A useful array: thedays is an array of constant (i.e you cannot
// modify them) pointers to constant (i.e. you cannot modify them) strings
  const char * const thedays[] = 
                      {"monday", "tuesday", "wednesday", "thursday",
		       "friday", "saturday", "sunday"};
//---
  int main(void){
  days today;
  printf("today    \tyesterday  \ttomorrow\n"
         "============================================\n");
  for (today=monday;today<=sunday;today++)
    printf("%s = %d \t %s = %d \t %s = %d\n", 
	   thedays[today], today, 
	   thedays[yesterday(today)], yesterday(today),
	   thedays[tomorrow(today)], tomorrow(today));
  }
