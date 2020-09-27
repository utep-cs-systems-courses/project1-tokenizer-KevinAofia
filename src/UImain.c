#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAXLIMIT 280 //max string limit is array of length 1000

int main()
{
  char userInput[MAXLIMIT]; //char *userInput

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
  char *copy;
  int i = 0;
  int c;
  while (c = getchar() != '\n') { //read chars until reach a \n
    userInput[i] = c;
    i++ ;
  };
  *(userInput+1) = '\0'; //add terminating char
  printf("%d\n",i);

  copy = copy_str(userInput,i+1); //update length
  printf("copied %s\n", copy);
}
