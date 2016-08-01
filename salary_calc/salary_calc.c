#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>
#include <argp.h>
#include "salary_calc.h"

/*
to run 
gcc salary_calc.c -lm -o salary_calc
EITHER

./salary_calc <amount>

OR

./salary_calc
What are you offered?
<amount>
 
salary | tax rate
11000  | 0%
43000  | 20%
43000  | 40%
150000 | 45%

if you earn 100,000, you pay
40% * (100,000 - 80,000) + 30% * (80,000 - 43,000) + 20%(43,000 - 11,000) = 25,500 GBP in taxes

todo:
national insurance
no personal allowance with income >150k
*/

struct rules_t get_country(int choice) {
/* Given a tax_regime value, return an initialised struct with tax rules */
  rules_t rules;
  TAX_REGIME tax_sys = choice;
  switch(choice) {
      case eUK:
        rules = UK_rules;
        break;

      case eCalifornia:
        rules = California_rules;
        break;
      
      case eRussia:
        rules = Russia_rules;
        break;
        
      default:
        printf("Error: Unrecognised case\n");
        break;
}
  return rules;
} 

int calc_taxes(float *salary_ptr, float *taxes_paid, rules_t tax_rules) {
  /* Given pointers to salary, amount of tax paid, return 0 if no
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


int print_salary_stats(float *salary_after_tax, rules_t country) {
  /* Given a pointer to salary after tax value (annual), 
     print out weekly and monthly allowance */

  //printf("%s\n", country.SIGN);

  printf("Salary after tax: %s%.2f\n", country.SIGN, *salary_after_tax); 
  printf("Your monthly allowance: %s%.2f\n", country.SIGN, *salary_after_tax/12);
  printf("Your weekly allowance: %s%.2f\n", country.SIGN, *salary_after_tax/52);

  return 0;
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
  
  rules_t tax_rules = get_country(1);
  errno = calc_taxes(salary_ptr, ptr_taxes_paid, tax_rules);
  
  *salary_after_tax_ptr = *salary_ptr - *ptr_taxes_paid;
  // *salary_after_tax_ptr = 25000.0;

  print_salary_stats(salary_after_tax_ptr, tax_rules);

  return 0;
}
