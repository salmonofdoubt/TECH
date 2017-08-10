


#include <stdio.h>

void print_fct(char *ptr[], int a);

int main (void) {

	char *message[8] = {"Four", "score", "and"};
	print_fct(message, 8);
	
	return 0;
}

void print_fct(char *ptr[], int a){
	int i;

	for (i = 0; i < a; i++)
		printf("%s ", ptr[a]);
}
