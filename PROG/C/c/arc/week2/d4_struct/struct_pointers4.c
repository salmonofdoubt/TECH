#include <stdio.h>
 
//Declare and define a structure to hold data
//Would like this to be in main but won't work

struct data{
    float amount;
    char fname[30];
    char lname[30];
    }  rec;
 
void print_rec(struct data x);
 
int main(void) {  
  
  printf("\nDonor's first (space) last name: ");
  scanf("%s %s", rec.fname, rec.lname);
      
  printf("\nDonation amount: ");
  scanf("%f", &rec.amount);
    
  print_rec(rec);
  return 0;
}
 
void print_rec(struct data x) {
  printf("\nDonor %s %s gave $%.2f.", rec.fname, rec.lname, rec.amount);
}