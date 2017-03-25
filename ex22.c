#include <stdio.h>
#include "ex22.h"

int THE_SIZE = 1000;

// static is the opposite of extern - you can only access it in ex22.c
static int THE_AGE = 27;

int get_age()
{
  return THE_AGE;
}

void set_age(int age)
{
  THE_AGE = age;
}

// though you cannot access static THE_AGE, 
// the 2 functions above can help you do it indirectly

double update_ratio(double new_ratio)
{
  static double ratio = 1.0;
  double old_ratio = ratio;
  ratio = new_ratio;

  return old_ratio;
}

void print_size()
{
  log_info("I think the size is: %d\n", THE_SIZE);
}
