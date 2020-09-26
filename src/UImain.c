#include <stdio.h>
#include "tokenizer.h"

int main()
{
  print_options();
  char test1 = '\0';
  char test2 = ' ';
  char *test3 = "Hello";
  char *test4 = "So long world";

  //printf("Test 1: %d :\n", space_char(test1));
  //printf("Test 2: %d :\n", non_space_char(test2));
  //printf("Test 3: %c :\n", *word_start(test3)); //return an address, so need to dereference
  //printf("Test 4: %c :\n", *word_terminator(test4)); //returns an address, so need to dereference
  printf("Test 5a: %d :\n", count_words(test3));
  printf("Test 5b: %d :\n", count_words(test4));
}
