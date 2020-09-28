#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  /*
  char test1 = '\0';
  char test2 = ' ';
  char *test3 = "Hello to all.";
  char *test4 = "My name is Kev.";
  printf("Test 1: %d :\n", space_char(test1));
  printf("Test 2: %d :\n", non_space_char(test2));
  printf("Test 3: %c :\n", *word_start(test3)); //return an address, so need to dereference
  printf("Test 4: %c :\n", *word_terminator(test4)); //returns an address, so need to dereference
  printf("Test 5a: %d :\n", count_words(test3));
  printf("Test 5b: %d :\n", count_words(test4));
  char input[1000];
  char c;
  int i = 0;
  c = getchar();
  while (c != '\n') {
    input[i] = c;
    c = getchar();
    i++;
  }
  char *copied;
  copied = copy_str(input,i);
  printf("Copied: %s\n", copied);
  char **tester = tokenize(copied);
  print_tokens(tester);
  free_tokens(tester);
  print_tokens(tester);
  */

  char input[240];
  char c;
  int num;
  int i = 0;
  char *copied;
  
  printf("Please select an option:\n");
  print_options();
  printf("Tokenizing > ");
  c = getchar();
  while (c != '\n') {
    input[i] = c;
    c = getchar();
    i++;
  }
  printf("\n");
  copied = copy_str(input,i);
  char **tokenized = tokenize(copied);
  print_tokens(tokenized);
  free_tokens(tokenized);
}

