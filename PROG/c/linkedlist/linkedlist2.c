// Required functions:
// node_t* append(dll_t*, const char* s);
// node_t* prepend(dll_t*, const char* s);
// node_t* delete(dll_t*, node_t*);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096

typedef struct node node_t;
typedef struct dll  dll_t;

struct node {
  char*   data;
  node_t* prev;
  node_t* next;
};

struct dll {
  node_t* first;
  node_t* last;
};

dll_t* create() {
  dll_t* list;                  // Declare the list pointer
  list = malloc(sizeof(dll_t)); // Allocate memory
  list->first = NULL;           // Initialize both pointers to NULL
  list->last  = NULL;           // ------- || ---------
  return list;                  // Finally, return the list pointer
}

node_t* create_node(const char* s) {
  node_t* new_node;                                // Create a new node
  new_node = (node_t*) malloc(sizeof(node_t));     // Allocate memory for the new node
  new_node->data = (char*) malloc(strlen(s) + 1);  // Allocate the memory for the data
  strcpy(new_node->data, s);                       // Copy over the data
  return new_node;
}

node_t* append(dll_t* list, const char* s) {
  node_t* new_node = create_node(s);
  if (list->first != NULL) {
list->last->next = new_node;
    
    new_node->prev = list->last;
  } else list->first = new_node;
  new_node->next = NULL;
  list->last = new_node;
  return new_node;
}

node_t* prepend(dll_t* list, const char* s) {
  node_t* new_node = create_node(s);
  if (list->first != NULL) {
    list->first->prev = new_node;
    new_node-> next = list->first;
  } else list->last = new_node;
  new_node->prev = NULL;
  list->first = new_node;
  return new_node;
}

node_t* delete(dll_t* list, node_t* node) {
  if (node->next == NULL) {
    if (node->prev == NULL) list->first = list->last = NULL;
    else node->prev->next = NULL;
  }
  if (node->prev == NULL) {
    if (node->next != NULL) node->next->prev = NULL;
  }
  node->prev = node->next = NULL;
  return node;
}

int main(int argc, char* argv[]) {
  FILE* file;
  char  current_char;
  char* line_buffer;
  node_t* current_node;
  int   current_buffer = BUFFER_SIZE;
  int   line_length = 0;
  dll_t* list = create();
  
  // Allocate initial memory
  line_buffer = (char*) malloc(BUFFER_SIZE);
  
  // First of all, check if the file name is present
  if (argc < 2) {
    puts("Usage: tac <file_name>");
    exit(EXIT_FAILURE);
  }
  const char* filename = argv[1];

  // Second, try to open the file
  file = fopen(filename, "r");
  if (file == 0) {
    puts("Can not open the file");
    exit(EXIT_FAILURE);
  }
  
  while((current_char = fgetc(file)) != EOF) {
    if (current_char != '\n') {
      if (line_length == current_buffer)
        line_buffer = (char*) realloc(line_buffer, (current_buffer *= 2));
      line_buffer[line_length++] = current_char;
    } else {
      line_buffer[++line_length] = '\0';
      line_length = 0;
      append(list, line_buffer);
    }
  }
  append(list, line_buffer);
  
  current_node = list->last;
  while (current_node != NULL) {
    printf("%s\n", current_node->data);
    current_node = current_node->prev;
  }
  
  // Finally, close the open file
  if (fclose(file) != 0) {
    puts("Could not close the file");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}


