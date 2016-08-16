#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>
#include "income_calc.h"
#include "parser.h"

/*
usage: 
./income_calc -a <amount> -l <location> [-m -s <amount_of_stock> <stock_quote>]

-a - salary offered without currency symbol

-s - stocks 

-l - Tax residence: 
         UK
         NYC
         California
         Seattle
*/


int calc_taxes(float *salary_ptr, float *taxes_paid, tax_t tax_rules) {
  /* Helper function to calculate amount of tax paid, given the rules and the salary. Can be applied for any contribution: NI in the UK, taxes elsewhere. 
     Given pointers to salary, amount of tax paid, return 0 if no
     errors.
     The value under taxes paid will be incremented 
     by the value of tax you pay at every bracket
  */

  float salary = *salary_ptr;

  int idx = 0;
  while (salary > tax_rules.SALARY_LIMITS[idx]) {
    idx += 1;
}
  idx -= 1; // incremented one too many times
  for(idx; idx > -1; idx--) {
    *taxes_paid += tax_rules.TAXRATES[idx]/100*(salary - tax_rules.SALARY_LIMITS[idx]);
    salary = tax_rules.SALARY_LIMITS[idx];
}
  return 0;
}


int print_salary_stats(float *salary_after_tax, tax_t country) {
  /* Given a pointer to salary after tax value (annual), 
     print out weekly and monthly allowance */

  if (strcmp(country.SIGN, "$") == 0 || strcmp(country.SIGN, "£") == 0) {
    printf("Salary after tax: %s%.2f\n", country.SIGN, *salary_after_tax); 
    printf("Your monthly allowance: %s%.2f\n", country.SIGN, *salary_after_tax/12);
    printf("Your weekly allowance: %s%.2f\n", country.SIGN, *salary_after_tax/52);
} else {
    printf("Salary after tax: %.2f %s\n", *salary_after_tax, country.SIGN); 
    printf("Your monthly allowance: %.2f %s\n", *salary_after_tax/12, country.SIGN);
    printf("Your weekly allowance: %.2f %s\n", *salary_after_tax/52, country.SIGN,);
} // end else
  return 0;
}

int Cali_full(float *salary_ptr, float *taxes_paid, int *married) {
  /* Helper function that internally calculates all tax contributions including healthcare charges. The value of all taxes paid will be added to the taxes_paid ptr  */ 
  return 0;
}

int NYC_full(float *salary_ptr, float *taxes_paid, int *married) {
  return 0;
}

int UK_full(float *salary_ptr, float *taxes_paid) {
  /* Given pointers to salary and taxes, applies respective tax rates and full costs of national insurance and assign it to respective pointers 
*/

  int errno;
  int ret = 0;
  tax_t taxes = UK;
  tax_t NI = UK_NI;
  // apply taxes
  errno = calc_taxes(salary_ptr, taxes_paid, taxes);
  if (errno == 0) {
    // apply national insurance
    errno = calc_taxes(salary_ptr, taxes_paid, NI);
    if (errno == 0) {
      return ret;
} 
} // if end
  ret = 1;
  return ret;
}

int main(int argc, char *argv[]) {
  /* the main initialises the necessary pointers, all functions take at least pointers to salary and taxes_paid. US tax funcs take pointer to married parameter */
  float salary, salary_after_tax;
  float *salary_after_tax_ptr = &salary_after_tax;
  float *salary_ptr = &salary;  
  float taxes_paid = 0;
  float *ptr_taxes_paid = &taxes_paid;
  int errno;
  
  
  // parser module - create and init an options struct 
  options_t * options = options_init();
  parser(argc, argv, options);
  int scenario = check_options(options);

  switch(options->location){
    case 0:
      errno = UK_full(salary_ptr, ptr_taxes_paid, country);
      break;

    case 1:
      break;
 
    case 2:
      break;

    case 3:
      break;

    default:
      printf("activated default - value of options->location = %d\n", options->location);
      break;
}

  if (errno == 0) 
{
    *salary_after_tax_ptr = *salary_ptr - *ptr_taxes_paid;
    print_salary_stats(salary_after_tax_ptr, country);
} else {
    return 1;
} // end else

  free(options);
  return 0;
}



