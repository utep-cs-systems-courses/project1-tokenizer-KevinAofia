#include <stdio.h>
#include <stdlib.h>
#include "history.h"
//#include "tokenizer.h"


List *init_history() {
  List *history = malloc(sizeof(List)); //allocate memory for a new struct List
  (*history).root = NULL; //starting root node is set to NULL
  //history->root = NULL;
  return history;
}

void add_history(List *list, char *str) {
  Item *newItem = malloc(sizeof(Item)); // allocate memory for this item
  (*newItem).str = str;
  if((*list).root == NULL) { //if list has no items
    (*list).root = newItem; //set root to first item
    (*newItem).id = 0; //this item is the first id
  }
  else {
    int idNumber = 1;
    Item *temp = (*list).root;
    while((*temp).next != NULL) {
      temp = (*temp).next;
      idNumber++;
    }
    (*temp).next = newItem;
    (*newItem).id = idNumber;
  }
}

char *get_history(List *list, int id) {
  if (id == 0) {
    return list->root->str; // if id is root, return roots string
  }
  Item *temp = (*list).root; //access root and items
  while((*temp).id != id) { //while id is not found
    temp = (*temp).next;
    if (temp == NULL) { //if a NULL value is found before id
      printf("NO HISTORY FOR THIS ID...TRY AGAIN");
      break;
    }
  }
  return (*temp).str;
}

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
