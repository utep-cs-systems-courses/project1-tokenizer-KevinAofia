#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" 
//Functions are defined here from the header file tokenizer.h
//NOTE:Zero terminators are not printable (therefore false) */

//Prints all options to the user
void print_options()
{
  printf("1) I want to tokenize\n");
  printf("2) Done tokenizing. ! EXIT ! \n");
}

//Return true(non-zero) if char c is a whitespace character('\t' or ' ' is a whitespace character)
int space_char(char c)
{
  if ( (c == ' ' || c == '\t') && c != '\0') { //if c is a whitespace character and not a \0
    return 1;
  }
  return 0;
}
  
//Return true(non zero) if char c is not a whitespace character(aka non whitespace character)
int non_space_char(char c)
{
  if ( (space_char(c) == 0) && c != '\0')  { //if space_char(c) is false
    return 1; //non_space_char is true since conditions in space_char failed
  }
  return 0; //must be a whitespace character
}
//Returns a pointer to the first non whitespace after a terminated word(aka return a pointer that
// points to the first character of a next word in a string
char *word_start(char *str)
{
  char *temp = str;
  while(space_char(*temp) == 1) {
    printf("NextCharS: %c \n",*temp);
    temp++;
  }
  return *&temp;
}

//Returns a pointer terminator char following the end of a word(*word)
char *word_terminator(char *word)
{
  char *temp = word;
  while(non_space_char(*temp) == 1) {
    printf("NextCharE: %c \n", *temp);
    temp++;
  }
  return *&temp;
}
  
//Counts the number of words in the string argument
int count_words(char *str)
{
  int count = 0;
  char *temp = str;
  
  char *startingPtr = word_start(temp);
  char *endingPtr = word_terminator(temp);

  char startingC = *startingPtr; 
  char endingC = *endingPtr;

  startingPtr = word_start(endingPtr);

  while (non_space_char(startingC) == 1) {
    count++;
    endingC = '\0'; //test case
    if ( endingC == '\0' ) {
      break;
    }
  }
  return count;
}

//Returns a fresly allocated new zero-terminated string containing,<len> chars from <inStr>
char *copy_str(char *inStr, short len);

//Returns a freshly allocated zero terminated vector of freshly allocated space-separated tokens
char **tokenize(char* str);

// Prints all tokens.
void print_tokens(char **tokens);

//Frees all tokens and the vector containing themx.
void free_tokens(char **tokens);
