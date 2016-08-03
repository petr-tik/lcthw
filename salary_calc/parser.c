#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/* Given a string of chars from the command line, return a struct with flags filled in 
allowed options:
   -a <amount>
   -l <place> [uk | NYC | russia | cali(fornia) | sea(ttle)
   -m married (default 0)
*/ 


void options_init(struct options_t *options) {
  /* Given a ptr to options struct, initialise it with default values */
  options->amount = 35000;
  options->married = 0; //won't change unless -m option
  options->location = 0;
}

int parse_amount(struct options_t *options, const char delim) {
/* Given a pointer to options struct and the delimiter, run the strtok */
  char *token = strtok(NULL, delim);
  float res = strtof(token); // if no conversion, returns 0
  if (res == 0) {
    return 1;
  } else {
  options->amount = strtof(token);
  return 0;
} // end else
}

int parse_location(struct options_t *options, const char delim) {
  /* Similar to parse_amount, takes a options_t ptr and delimiter, to fill the struct with location value */
  char *token = strtok(NULL, delim);
  short int = strtoi
}

int parser(char *arguments, struct options_t *options) {
/* Given pointers: to arg string and to options struct, return errcode and modiy the struct at pointer */
  char *token;
  const char delim = " ";
  token = strtok(arguments, delim);
  while(token != NULL) {
    token = strtok(arguments, delim);
}
}
