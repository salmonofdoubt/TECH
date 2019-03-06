#include <stdio.h>
#include <stdlib.h>

//node object 
typedef struct node_type {
	int data;
	struct node_type *next;
} node;

//list object
typedef node *list;

int main(){
	
	list head, temp;
	char ch;
	int n;
	head = NULL;
	printf("Enter Data? (y/n) \n");
	scanf("%c", &ch);

	while(ch == 'y' || ch == 'Y'){
		printf("Give Data: ");
		scanf("%d", &n);
		temp = (list)malloc(sizeof(node));
		temp->data = n;
		temp->next = head;
		head = temp;
		printf("More Data? (y/n) \n");
		scanf("\n%c", &ch);
	}
	
	temp = head;	
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
