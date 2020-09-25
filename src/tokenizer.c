#include <stdio.h>
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
  if (c == '\t' || c == ' ')
    {
      printf("True\n");
      return 1;
    }
  else
    {
      printf("False\n");
      return 0;
    }
}
  
//Return true(non zero) if char c is not a whitespace character(aka non whitespace character)
int non_space_char(char c);


//Returns a pointer to the first non whitespace after a terminated word(aka return a pointer that
// points to the first character of a next word in a string
char word_start(char *str); 

//Returns a pointer terminator char following the end of a word(*word)
char *word_terminator(char *word);

//Counts the number of words in the string argument
int count_words(char *str);

//Returns a fresly allocated new zero-terminated string containing,<len> chars from <inStr>
char *copy_str(char *inStr, short len);

//Returns a freshly allocated zero terminated vector of freshly allocated space-separated tokens
char **tokenize(char* str);

// Prints all tokens.
void print_tokens(char **tokens);

//Frees all tokens and the vector containing themx.
void free_tokens(char **tokens);
