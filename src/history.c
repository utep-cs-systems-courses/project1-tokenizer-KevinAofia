//File defining functions from history.h file

#include "history.h"

//char *variable = (custage> 21) ? "True" : "False"; //Conditional operator

/* Initialize the linked list to keep the history. */
List* init_history()
{
  return 0;
}

//List* list - the linked list
//char* str - the string to store
//add an item to the end of a linked list
void add_history(List *list, char *str)
{
  printf("Works");
}

//List* list - the linked list
//int id - the id of the Item to find
//Return the list corresponding to the id
char *get_history(List *list, int id)
{
  return list;
}

//Prints the entire contents of the list
void print_history(List *list)
{
  printf("Content of list");
}

//Frees the history list and the strings that it references
void free_history(List *list)
{
  printf("All history is freed");
}
