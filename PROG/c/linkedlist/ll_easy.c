//Basic double linked list fragment

#include <stdio.h>
#include <stdlib.h>

struct dllist {
 int number;
 struct dllist *next;
 struct dllist *prev;
};

struct dllist *head, *tail;

void append_node(struct dllist *lnode);
void insert_node(struct dllist *lnode, struct dllist *after);
void remove_node(struct dllist *lnode);

int main(void) {
 struct dllist *lnode;
 int i = 0;

 /* add some numbers to the double linked list */
 for(i = 0; i <= 5; i++) {
  lnode = (struct dllist *)malloc(sizeof(struct dllist));
  lnode->number = i;
  append_node(lnode);
 }

 /* print the dll list */
 for(lnode = head; lnode != NULL; lnode = lnode->next) {
  printf("%d\n", lnode->number);
 }

 /* destroy the dll list */
 while(head != NULL)
  remove_node(head);

 return 0;
}



