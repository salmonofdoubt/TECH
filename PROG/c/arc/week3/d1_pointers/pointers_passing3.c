/* LIST1507.c: Day 15 Listing 15.7 */
/* Inputs a list of strings from the keyboard, */
/* sorts them, then displays them on the screen. */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXLINES 25
 
int get_lines(char *lines[]);
void sort(char *p[], int n);
void print_strings(char *p[], int n);
 
char *lines[MAXLINES];


int main(void) {
	int number_of_lines;
	
	/* Read in the lines from the keyboard. */
	number_of_lines = get_lines(lines);
	
	if (number_of_lines < 0) {
		printf("Memory allocation error");
		exit(-1);
	}
 
	sort(lines, number_of_lines);
	print_strings(lines, number_of_lines);
	return 0;
}
 
int get_lines(char *lines[]) {
	int n = 0;
	char buffer[80];	/* Temp storage for each line. */
	
	printf("Enter one line at a time; "
			 "enter a blank when done.");

	while ((n < MAXLINES) && (gets(buffer) != 0) &&
			 (buffer[0] != '\0')) {
		if ((lines[n] = (char *)malloc(strlen(buffer)+1)) == NULL)
			return -1;
		strcpy(lines[n++], buffer);
	}
	return n;
}
 
void sort(char *p[], int n) {
	int a, b;
	char *x;
	
	for (a = 1; a < n; a++) {
		for (b = 0; b < n-1; b++) {
			if (strcmp(p[b], p[b+1]) > 0) {
				x = p[b];
				p[b] = p[b+1];
				p[b+1] = x;
			}
		}
	}
}

void print_strings(char *p[], int n) {
	int count;
	
	for (count = 0; count < n; count++)
		printf("\n%s", p[count]);
}

/*
In the get_lines() function, input is controlled by the while statement on lines 42 – 43, which read as follows:
 
while ((n < MAXLINES) && (gets(buffer) != 0) &&
     (buffer[0] != '\0'))
 
The condition tested by the while has three parts. The first part, n < MAXLINES, ensures that the maximum number of lines has not been input already. The second part, gets(buffer) != 0, calls the gets() library function to read a line from the keyboard into buffer, and verifies that end-of-file or some other error has not occurred. The third part, buffer[0] != '\0', verifies that the first character of the line just input is not the null character, which would signal that a blank line was entered.
 
If any of the three conditions is not satisfied, the while loop terminates, and execution returns to the calling program, with the number of lines entered as the return value. If all three conditions are satisfied, the following if statement on line 44 is executed:
 
if ((lines[n] = 
   (char *)malloc(strlen(buffer)+1)) == NULL)
 
The first part of the condition calls  malloc() to allocate space for the string just input. The strlen() function returns the length of the string passed as an argument; the value is incremented by 1 so that malloc() allocates space for the string plus its terminating null character.
 
The library function malloc(), you might remember, returns a pointer. The statement assigns the value of the pointer returned by malloc() to the corresponding element of the array of pointers. If malloc() returns NULL, the if loop returns execution to the calling program with a return value of –1. The code in main() tests the return value of get_lines() and whether a value less than 0 is returned; lines 24 – 27 report a memory allocation error and terminate the program.
 
If the memory allocation was successful, the program uses the strcpy() function on line 47 to copy the string from the temporary storage location buffer to the storage space just allocated by malloc(). The while loop then repeats, getting another line of input.
 
Once execution returns to main() from get_lines(), the following has been accomplished (assuming a memory allocation error did not occur):
 
    A number of lines of text have been read from the keyboard and stored in memory as null-terminated strings.
 
    The array lines[] contains a pointer to each string. The order of pointers in the array is the order in which the strings were input.
 
    The variable number_of_lines holds the number of lines that were input.
 
Now it's time to sort. Remember, you're not actually going to move the strings around, only the order of the pointers in the array lines[]. Look at the code in the function sort(). It contains one for loop nested in another (lines 56 – 64). The outer loop executes number_of_lines - 1 times. Each time the outer loop executes, the inner loop steps through the array of pointers, comparing (string n) with (string n+1) for n = 0 to n = number_of_lines - 1. The comparison is performed by line 58's library function strcmp(), which receives pointers to two strings. The function strcmp() returns one of the following:
 
A value greater than 0 if the first string is greater than the second string.
 
Zero if the two strings are identical.
 
A value less than zero if the second string is greater than the first string.
 
In the program, a return value from strcmp() of greater than 0 means the first string is "greater than" the second string, and they must be swapped (that is, their pointers in lines[ ] must be swapped). This is done with the help of a temporary variable x. Lines 59, 60, and 61 perform the swap.
 
When program execution returns from sort(), the pointers in lines[] are ordered properly: a pointer to the "lowest" string is in lines[0], a pointer to the next "lowest" is in lines[1], and so on. Say, for example, you entered the following five lines, in this order:
 
dog
apple
zoo
program
merry
 
Finally, the program calls the function print_strings() to display the sorted list of strings on the screen. This function should be familiar from previous examples in this unit.
*/