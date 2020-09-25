#include <stdio.h>
#include "tokenizer.h"

int main()
{
  int choice; //Declaring int variable for user choice

  printf("\tTOKENIZE!!!!\n");
  printf("\tReady to tokenize?\n");
  
  print_options();
  
  char *e = "My name is Kev";
  printf("Count:%d\n",count_words(e));
}
