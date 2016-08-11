#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>
#include "salary_calc.h"
#include "parser.h"

/*

usage: 
./salary_calc -a <amount> -l <location> [-m -s <amount_of_stock> <stock_quote>]

-a - salary offered without currency symbol

-s - stocks 

-l - Tax residence: 
         UK
         NYC
         California
         Seattle
         Russia

todo:
UK:
*/

struct tax_t get_country(int choice) {
/* Given a tax_regime value, return an initialised struct with tax rules */
  tax_t rules;
  switch(choice) {
      case eUK:
        rules = UK;
        break;

      case eCalifornia:
        rules = California;
        break;
      
      case eRussia:
        rules = Russia;
        break;

      case eNYC:
        //rules = NYC;
        break;

      case eSeattle:
        //rules = Seattle;
        break;
        
      default:
        printf("Error: Unrecognised case\n");
        break;
}
  return rules;
}


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
  /* Function that calls as  */ 

}

int NYC_full(float *salary_ptr, float *taxes_paid, int *married) {

}

int UK_full(float *salary_ptr, float *taxes_paid) {
  /* Given pointers to salary and taxes, applies respective tax rates and full costs of national insurance and assign it to respective pointers */
  int errno;
  tax_t taxes = UK;
  tax_t NI = UK_NI;
  errno = calc_taxes(salary_ptr, taxes_paid, taxes);
  if (errno == 0) {
    errno = calc_taxes(salary_ptr, taxes_paid, NI);
    if (errno == 0) {
      return 0;} 
    else 
      {return 1;} 
  
  } else {
  return 1;
  }

}

int main(int argc, char *argv[]) {
  float salary, salary_after_tax;
  float *salary_after_tax_ptr = &salary_after_tax;
  float *salary_ptr = &salary;  
  float taxes_paid = 0;
  float *ptr_taxes_paid = &taxes_paid;
  int errno;

  printf("What are you offered? \n");
  fscanf(stdin, "%f", salary_ptr);
  
  tax_t tax_rules = get_country(0);
  tax_t NI_rates = UK_NI;
  errno = calc_taxes(salary_ptr, ptr_taxes_paid, tax_rules);
  errno = calc_taxes(salary_ptr, ptr_taxes_paid, NI_rates);
  *salary_after_tax_ptr = *salary_ptr - *ptr_taxes_paid;
  // *salary_after_tax_ptr = 25000.0;

  print_salary_stats(salary_after_tax_ptr, tax_rules);

  return 0;
}
