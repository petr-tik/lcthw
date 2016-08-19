#ifndef _PARSER_H_
#define _PARSER_H 

/* Module for CLI interaction - receiving and processing terminal commands, breaking if they are wrong/insufficient, otherwise filling the options struct */

void show_version();

void show_help();

typedef struct options_t {
  float amount; // mandatory
  float stock_amount; // optional 
  char stock_quote[6]; // optional 
  int married; // optional 
  short int location; // mandatory
} options_t;

int check_options(struct options_t *options);

options_t * options_init();

int parser(int argc, char *argv[], struct options_t *options);

short int parse_location(const char *loc_arg);

// debugging/testing funcs 
// won't actually need them for final executable

void print_options(struct options_t *options);


#endif
