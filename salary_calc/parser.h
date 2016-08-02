#ifndef _PARSER_H_
#define _PARSER_H 

typedef struct options_t {
  float amount;
  int married;
  char country;
} options_t;

int parser(char *arguments, struct options_t *options);

#endif
