#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[240];
  char c;
  char temp;
  int num;
  int i = 0;
  
  char *copied;
  char *bool = "True";
  char **tokenized;

  List *history = init_history();
  
  while(bool != "False") {

    printf("Please select an option below (1-4) :\n");
    printf("1)Tokenize\n");
    printf("2)Show History\n");
    printf("3)Recall Item\n");
    printf("4)Exit\n"); 
    scanf("%d",&num);
    scanf("%c",&temp); //scan null char from prev scan
    if (num == 1) {
      printf("Tokenizing >>> ");
      c = getchar();
      while (c != '\n') {
	input[i] = c;
	c = getchar();
	i++;
      }
      copied = copy_str(input,i);
      i = 0; // resetting index for next input(if any)
      tokenized = tokenize(copied);
      print_tokens(tokenized);
      free_tokens(tokenized);
      printf("\n");
    }
    else if (num == 2) {
      printf("Showing history\n");
      print_history(history);
    }
    else if (num == 3) {
      printf("Recall an item\n");
      //get_history(history,id);
    }
    else if (num == 4) {
      printf("Exiting\n");
      bool = "False";
      exit(0);
    }
    else {
      printf("Not a valid option....Try again\n");
    }
  }
  return 0;
}
