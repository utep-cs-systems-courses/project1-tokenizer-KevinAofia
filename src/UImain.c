#include <stdio.h>
#include "tokenizer.h"

int main()
{
  int choice; //Declaring int variable for user choice

  printf("\tTOKENIZE!!!!\n");
  printf("\tReady to tokenize?\n");
  
  print_options();
  scanf("%d" , &choice); //Read int number from user

  int c = 'a';
  space_char(c);
}
