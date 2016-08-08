#ifndef _PARSER_H_
#define _PARSER_H 

void show_version();

void show_help();

typedef struct options_t {
  float amount; // mandatory
  float stock_amount; // optional 
  int married; // optional 
  char stock_quote[6]; // optional 
  short int location; // mandatory
} options_t;

int check_options(struct options_t *options);

options_t * options_init();

void print_options(struct options_t *options);

int parser(int argc, char *argv[], struct options_t *options);


#endif
