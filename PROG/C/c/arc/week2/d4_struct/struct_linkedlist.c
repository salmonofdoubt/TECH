#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[]){
/*
The second member of the type data is a pointer to type data. In other words, the structure includes a pointer to its own type. This means that one instance of type data can point to another instance of the same type. This is how you create the links in a linked list; each structure points to the next structure in the list.
*/
  int value;
  
  struct data {
    char name[10];
    int test;
    struct data *p_next;
  };

  struct data *p_next;
  p_next = malloc(sizeof(struct data));
  printf("%ld", sizeof(struct data));

/*
Structures allocated with malloc() have no name per se, so you can not use the membership operator(.) to access their members. Always use a pointer and the indirect membership operator (->).
*/
  p_next->test = 3;
  printf("\n%d", p_next->test);

  return 0;
}