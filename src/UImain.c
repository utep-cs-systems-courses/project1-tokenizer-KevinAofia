#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  print_options();
  
  /*char test1 = '\0';
  char test2 = ' ';
  char *test3 = "Hello to all.";
  char *test4 = "My name is Kev.";
  printf("Test 1: %d :\n", space_char(test1));
  printf("Test 2: %d :\n", non_space_char(test2));
  printf("Test 3: %c :\n", *word_start(test3)); //return an address, so need to dereference
  printf("Test 4: %c :\n", *word_terminator(test4)); //returns an address, so need to dereference
  printf("Test 5a: %d :\n", count_words(test3));
  printf("Test 5b: %d :\n", count_words(test4));*/

  char *a;
  int length = 0;
  scanf("%s",a);
  a = copy_str(a,length);
  printf("copied %s\n", a);
  //a = malloc(length * sizeof(char));
  // char *inString = (*char)malloc(sizeof(int) * n); //allocate at run time/dynamic allocatation
}
