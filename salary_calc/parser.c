#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Given a string of chars from the command line, return a struct with flags filled in 
allowed options:
   -a <amount>
   -l <place> [uk | NYC | russia | cali(fornia) | sea(ttle)
   -m married (default 0)
*/ 

typedef struct options_t {
  float amount;
  int married;
  char country;
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
