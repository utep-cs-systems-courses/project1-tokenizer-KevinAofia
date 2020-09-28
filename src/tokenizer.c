#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//Functions are defined here from the header file tokenizer.h
//NOTE:Zero terminators are not printable (therefore false) */

//Prints all options to the user
void print_options()
{
  printf("1) Tokenize\n");
  printf("2) Exit\n");
}

//Return true(non-zero) if char c is a whitespace character('\t' or ' ' is a whitespace character)
int space_char(char c)
{
  if (c == ' ' || c == '\t') { //if c is a whitespace character
    return 1;
  }
  return 0;
}
  
//Return true(non zero) if char c is not a whitespace character(aka non whitespace character)
int non_space_char(char c)
{
  if ( (space_char(c) == 0) && c != '\0')  { //if space_char(c) is false and c is not a \0
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
    //printf("FindingStartingC:'%c'\n",*temp);
    temp++;
  }
  return temp;
}

//Returns a pointer terminator char following the end of a word(*word)
char *word_terminator(char *word)
{
  char *temp = word;
  while(non_space_char(*temp) == 1) {
    //printf("FindingEndC:'%c'\n", *temp);
    temp++;
  }
  return temp;
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
 
  while (non_space_char(startingC)) { //if the starting char is a char
    count++; //we know that there is at least one/another word
    if ( endingC == '\0' ) { //if the word ends in a term char
      return count; //return the current count
    }
    startingPtr = word_start(endingPtr); //update starting * to point at next starting c
    startingC = *startingPtr; //update starting c with the new value at starting *
    endingPtr = word_terminator(startingPtr);//update ending * to the point to next ending c
    endingC = *endingPtr;//update ending c with new value at ending *
  }
  return 0; //Return 0 if count_words fails
}

//Returns a freshly allocated new zero-terminated string containing,<len> chars from <inStr>
char *copy_str(char *inStr, short len)
{
  char *copy = malloc( (len + 1) * sizeof(char)); //allocate memory (add 1 for \0 character) 
  int i = 0;
  while (i < len) { //while index is less than length of passed array
    copy[i] = inStr[i]; //this is equivalent to saying *copy = *inStr
    i++; //increment index for next character in string
  }
  copy[i+1] = '\0'; //set next address value to terminating character
  return copy;
}

//Returns a freshly allocated zero terminated vector of freshly allocated space-separated tokens
char **tokenize(char *str) {
  int wordCount = count_words(str);
  char **tokens = malloc( (wordCount + 1) * sizeof(char*));
  char *startingPtr = word_start(str);
  char *endingPtr = word_terminator(str);
  
  int i = 0;
  while (i < wordCount ) { //not to exceed number of words
    tokens[i] = copy_str( startingPtr , endingPtr - startingPtr ); //string pointer/len of word
    startingPtr = word_start(endingPtr);
    endingPtr = word_terminator(startingPtr);
    i++;
  }
  tokens[i+1] = '\0'; //put term character in last array
  printf("Done\n");
  return tokens;
}

// Prints all tokens.
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL) {
    printf("Token %d: \"%s\" \n",i, tokens[i]);
    i++;
  }
  printf("All tokens are printed.\n");
}

//Frees all tokens and the vector containing themx.
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL) {
    free(tokens[i]); //free what the pointer is pointing too
    i++;
  }
  free(tokens); //free our pointer itself
  printf("All tokens are freed.\n");
}
