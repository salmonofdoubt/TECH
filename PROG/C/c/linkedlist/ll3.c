//wachira -- the way to do it

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dlink_node DN;  
//typedef to assign alternative names to existing types
//can now create dlink_node-variables of type DN.

struct dlink_node{
  char * data;
  DN * prev;
  DN * next;
};
//here we declare the content of var "dlink_node".


struct dlink_node * reset_to_first( struct dlink_node * first ){
  while(first->prev != NULL)
    first = first->prev;
  return first;
}
//

struct dlink_node * reset_to_last( struct dlink_node * first ){
  while(first->next != NULL)
    first = first->next;
  return first;
}


struct dlink_node * append(struct dlink_node *first, const char *data){
  struct dlink_node * first_data = first;
  first_data = reset_to_last(first_data);


struct dlink_node * new_node = (struct dlink_node *) malloc(sizeof(struct dlink_node *));

  first_data->next = new_node;

  char * thedata = (char *) malloc(strlen(data) + 1);
  strcpy(thedata, data);
  new_node->data = thedata;

  new_node->prev = first;
  new_node->next = NULL;

  return first;
}

struct dlink_node * prepend(struct dlink_node *first, const char *data){
  struct dlink_node * first_data = first;
  first_data = reset_to_first(first_data);

  struct dlink_node * new_node = (struct dlink_node *) malloc(sizeof(struct dlink_node *));

  first_data->prev = new_node;

  char * thedata = (char *) malloc(strlen(data) + 1);
  strcpy(thedata, data);
  new_node->data = thedata;

  new_node->next = first;
  new_node->prev = NULL;

  new_node = NULL;
  thedata = NULL;

  return first;
}

struct dlink_node * delete(struct dlink_node *first, struct dlink_node *node){
  struct dlink_node *first_data = reset_to_first(first);

  /*we are at the beggining*/
  for(;first_data != NULL; first_data = first_data->next ){
    if(strcmp(first_data->data, node->data) == 0){
      printf("delete: %s = %s\n", first_data->data, node->data);
    /*we are confident this is the node to delet*/
      (first_data->prev)->next = (first_data->next);
	    
      if((first_data->next) != NULL){
	(first_data->next)->prev = (first_data->prev);
      }
    /*dissociate the item from data structure*/
      first_data->next = NULL;
      first_data->prev = NULL;
    /*then free the memory*/
      free(first_data->data);
      free(first_data);

      node = NULL;
      break;
    }
  }

  return first;
}

struct dlink_node * populate(struct dlink_node *first){
  char *names[] = {"Andrew", "Hong Li", "Andre", "Ribeiro"};
  /*iterate to the last and add*/
  int num = sizeof(names) / sizeof(char **);
  //  printf("%d\n", num);
  char * name = NULL;
  int i = 0;
  if(first == NULL){
    first = (struct dlink_node *) malloc(sizeof(struct dlink_node *));
    first->next = NULL;
    first->prev = NULL;
    name = (char *) malloc(strlen(names[0]) + 1);
    strcpy(name, names[0]);
    first->data = name;
    name = NULL;

    i = 1;
  }

  struct dlink_node * new_node = NULL;
  for(;i < num; i++){
    new_node = (struct dlink_node *) malloc(sizeof(struct dlink_node *));

    name = (char *) malloc(strlen(names[i]) + 1);
    strcpy(name, names[i]);

    //printf("NAME: %s\n", name);

    new_node->data = name;
    name = NULL;
    //printf("new_node->data = %s\n", new_node->data);

    new_node->prev = first;
    new_node->next = NULL;

    first->next = new_node;
    first = new_node;

    //  printf("first->data = %s\n", first->data);
    new_node = NULL;
  }
  
  return first;
}

void printlist(struct dlink_node * first){
  struct dlink_node * save = first;

  for(;save != NULL; save = save->next){
    printf("%s\n", save->data);
  }
  //  first = save;
}

#ifndef _RUN_LISTS_MAIN_
#define _RUN_LISTS_MAIN_
int main(int argc, char * argv[]){

  struct dlink_node *list = NULL;

  /*populate the list*/
  list = populate(list);
  //printf("NAME - %s\n", list->data);
  list = reset_to_first(list);
  //printlist(list);

  list = reset_to_first(list);
  list = append(list, "Grace Nyakio");
  //printlist(list);

  list = append(list, "Pastor Stephen Apple");
  //printlist(list);

  list = append(list, "Jesus Christ");
  //printlist(list);

  list = reset_to_first(list);
  struct dlink_node *to_delete = list->next;
  
  list = delete(list, to_delete);


  //  list = prepend(list, "Hong Li Lu");
  list = reset_to_first(list);
  list = prepend(list, "Mom");
  list = append(list, "momma");
  //  list = append(list, "Hong Li Lu");
  printlist(list);
  //  list = populate(list);
  //  list = populate(list);
  //  list = populate(list);
  //printlist(list);

  return 0;
}
#endif
