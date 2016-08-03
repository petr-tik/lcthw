#ifndef _PARSER_H_
#define _PARSER_H 

typedef struct options_t {
  float amount;
  int married;
  short int location;
} options_t;

int parser(char *arguments, struct options_t *options);

int parse_amount(struct options_t *options, const char delim);

int parse_location(struct options_t *options, const char delim);

#endif
