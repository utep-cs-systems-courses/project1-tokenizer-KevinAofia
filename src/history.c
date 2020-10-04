#include <stdio.h>
#include <stdlib.h>

#include "history.h"
#include "tokenizer.h"


List *init_history() {
  List *history = malloc(sizeof(List)); //allocate memory for a new struct List
  (*history).root = NULL; //starting root node is set to NULL
  //history->root = NULL;
  return history;
}

void add_history(List *list, char *str) {
  return;
}

char *get_history(List *list, int id) ;


void print_history(List *list) {
  Item *temp = (*list).root;
  printf("\t*****History*****\n");
  while(temp != NULL) {
    printf("ID: %d\nString: %s\n",(*temp).id,(*temp).str);
    //printf("ID: %d\nString: %s\n",temp->id,temp->str); //equivalent to line above
    temp = (*temp).next;
  }
  printf("\t*****End of history*****\n");
}

void free_history(List *list) {
  Item *temp = (*list).root;
  Item *temp2;
  while(temp != NULL) { //while element present in linked list
    temp2 = temp;
    free(temp2);
    temp = (*temp).next; //store temp to the next element    
  }
}
