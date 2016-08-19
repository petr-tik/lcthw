#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/* Module responsible for parsing the command line arguments.
   Receives argc and argv and iterates over them to fill in a previously initialised 
 */ 

// testing, run
// gcc parser.c -o test

/* Given a string of chars from the command line, return a struct with flags filled in 
allowed options:
   -a <amount>
   -l <location> [uk | NYC | russia | cali(fornia) | sea(ttle)

Optional:
   -s <amount_of_stock> <stock_quote> 
   -m married (default 0)

*/ 

void show_help() {
  printf("Usage:\n income_calc [--version] [--help]\n [-a <amount> -l <location>]\n\nOptional:\n [-s <amount_of_stock> <stock_quote>]\n [-m married] (default 0)\n\n");
}

void show_version() {
  printf("Salary calculator version 0.2\n");
}

options_t * options_init() {
  /* Given a ptr to options struct, initialise it with default values */
  options_t *options = malloc(sizeof(struct options_t));
  options->amount = -1;
  options->married = 0; // won't change unless -m option
  options->location = -1;
  options->stock_amount = -1;
  memcpy(options->stock_quote, "", sizeof(""));
  return options;
}


void print_options(struct options_t *options){
  // ONLY FOR DEBUGGING - REMOVE FROM END PRODUCT
  printf("Salary is: %f\n", options->amount);
  printf("You have %.1f shares in %s\n", options->stock_amount, options->stock_quote); 
  if (options->married == 0) {
    printf("Not married\n");
} else {
    printf("married\n"); }
  printf("The location code is: %d\n", options->location);
}

short int parse_location(const char *loc_arg) {
  /* Given a pointer to char array i.e. command line location argument, returns the location code, which is assigned to the options->location variable 
1 - UK
2 - NYC
3 - Seattle
4 - California
*/
  char dest[10];
  strcpy(dest, loc_arg); 
  for(int idx = 0; idx < strlen(dest); idx++) {
    dest[idx] = tolower(dest[idx]);
} // end for
  if ((strcmp(dest, "uk") == 0) || (strcmp(dest, "london") == 0))
{
  return 1;
} 
  else if ((strcmp(dest, "new york") == 0) || 
           (strcmp(dest, "ny") == 0) ||
           (strcmp(dest, "nyc") == 0))
{
  return 2;
} 
  else if (strcmp(dest, "seattle") == 0)
{
  return 3;
}
  else if ((strcmp(dest, "california") == 0) || (strcmp(dest, "cali") == 0))
{
  return 4;
}
  else 
{
  return -1;
}
}


int parser(int argc, char *argv[], struct options_t *options) {
/* Given pointers: to arg string and to options struct, modiy the struct at pointer and return info code
 */
  if (argc == 2 && (strcmp(argv[1], "--version") == 0)) {
      show_version();    
}

  for (int idx = 1; idx < argc; idx++) {
    printf("Arg %d/%d: %s\n", idx, argc - 1, argv[idx]);
    if (strcmp(argv[idx], "-m") == 0) // set the marriage flag to 1
{
      options->married = 1; 
} 
    else if (strcmp(argv[idx], "-a") == 0) // salary amount
{
      options->amount = atof(argv[idx+1]); 
}
    else if (strcmp(argv[idx], "-l") == 0) // location
{
      options->location = parse_location(argv[idx+1]);
}
    else if (strcmp(argv[idx], "-s") == 0) // stock options
{
      options->stock_amount = atof(argv[idx+1]); // amount 
      memcpy(options->stock_quote, argv[idx+2], sizeof(argv[idx+2])); // quote
}
}  // for end
  return 0;
}
 // parser end


int check_options(options_t *options) {
  /* Used after parser. Takes a pointer to options and checks how many option flags have been filled in and returns an action code:
   0 - not enough info on necessary info - location and amount
   1 - only basic info
   2 - full info including stocks

   The return code and location flag will be used to call the right tax method 
*/
  int ret = 0;
  if ((options->amount != -1) && (options->location != -1))
{
  ret += 1;
}
  if (options->stock_amount != -1 && strcmp("", options->stock_quote) != 0)
{
  ret += 1;
}
  return ret;
}

int main(int argc, char *argv[]) {
// testing it out
  options_t * options = options_init();
  parser(argc, argv, options);
  print_options(options);
  free(options);
  return 0;
}
