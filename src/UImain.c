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
  word_start(c);
  
  char *d = "hi ih";
  *word_terminator(d);
  
  // char *e = 'My name is Kev';
  //count_words(e);
}
