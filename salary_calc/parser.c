#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// testing, run
// gcc parser.c -o test && ./test

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

void print_options(struct options_t *options){
  printf("Salary is: %f\n", options->amount);
  if (options->married) {
    printf("Not married\n");
} else {
    printf("married\n"); }
  printf("The location code is: %d\n", options->location);
}

int parse_amount(struct options_t *options, const char *delim) {
/* Given a pointer to options struct and the delimiter, run the strtok */
  char *token = strtok(NULL, delim);
  float res = strtof(token); // if no conversion, returns 0
  if (res == 0) {
    return 1;
  } else {
  options->amount = strtof(token);
  return 0;
} // end else

} // end func

int parse_location(struct options_t *options, const char *delim) {
  /* Similar to parse_amount, takes a options_t ptr and delimiter, to fill the struct with location value */
  char *token = strtok(NULL, delim);
  short int loc = atoi(token);
  options->location = loc;
  return 0;
  
} // func end

int parser(char *arguments, struct options_t *options) {
/* Given pointers: to arg string and to options struct, return errcode and modiy the struct at pointer */
  char *token;
  const char *delim = " ";
  token = strtok(arguments, delim);
  while(token != NULL) {
    token = strtok(arguments, delim);
    if (token == "-m") {
      options->married = 1;
} 
    else if (token == "-a") {
      parse_amount(options, delim);
} 
    else if (token == "-l") {
      parse_location(options, delim);
}
} // while end
} // parser end

int main(int argc, char *argv[]) {
// testing it out
  options_t *args;
  options_init(args);
  print_options(args);
  return 0;
}
