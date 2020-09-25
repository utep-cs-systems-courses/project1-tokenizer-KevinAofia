#include <stdio.h>
#include "tokenizer.h"

int main()
{
  int choice; //Declaring int variable for user choice

  printf("\tTOKENIZE!!!!\n");
  printf("\tReady to tokenize?\n");
  
  print_options();

  int a = '\t';
  space_char(a);
  
  int b = 't';
  non_space_char(b);
  
  char *c = "hi hey";
  char *me = word_start(c);
  printf(&me[0]);
  printf("\n");
  
  char *d = "hi ih";
  char *my = word_terminator(d);
  printf(&my[0]);
  printf("\n");
  
  char *e = "My name is Kev";
  count_words(e);
}
