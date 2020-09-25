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
  if (c == '\t' || c == ' ') {
    return 1; //True
  }
  else {
    return 0; //False
  }
}
  
//Return true(non zero) if char c is not a whitespace character(aka non whitespace character)
int non_space_char(char c)
{
  if(c != '\t' && c != ' ') {
    return 1; //True
  }
  else {
    return 0; //False
  }
}

//Returns a pointer to the first non whitespace after a terminated word(aka return a pointer that
// points to the first character of a next word in a string
char *word_start(char *str)
{
  int i = 0; //dereference at index 0 of an array
  while (non_space_char(str[i]) != 1) { //while character at index i is not a non whitespace
    i++; //check next character
  }
  //printf("%c\n",str[i]); //uncomment to test
  return &str[i]; //pointer to str at [i]
}

//Returns a pointer terminator char following the end of a word(*word)
char *word_terminator(char *word)
{
  int i = 0;
  while (space_char(word[i]) != 1) {
    i++;
  }
  //printf("End of word found at index: %d\n",i);
  return &word[i]; //pointer to word at [i]
}
  
//Counts the number of words in the string argument
int count_words(char *str)
{
  int count = 0;
  char *p1 = word_start(str);
  char *p2 = word_terminator(p1);
  
  while(non_space_char(*p1) == 1){
    count++;
    p2 = word_terminator(p1);
    if ((*p2) == '\0'){
      break;
    }
    p1 = word_start(p2);
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
