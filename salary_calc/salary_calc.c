#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

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
*/

float TAXRATES[] = {0, 20, 40, 45};
float SALARY_LIMITS[] = {0, 11000, 43000, 150000};

int calc_taxes(float *salary_ptr, float *taxes_paid) {
  /* Given pointers to salary, amount of tax paid, return 0 if no
     errors.
     The value under taxes paid will be incremented 
     by the value of tax you pay at every bracket
  */
  int idx = 0;
  float salary = *salary_ptr;
  while (salary > SALARY_LIMITS[idx]) {
    idx += 1;
}
  idx -= 1;
  for(idx; idx > -1; idx--) {
    *taxes_paid += TAXRATES[idx]/100*(salary - SALARY_LIMITS[idx]);
    salary = SALARY_LIMITS[idx];
}
  return 0;
}


int salary_stats(float *salary_after_tax) {
  /* Given a pointer to salary after tax value (annual), 
     print out weekly and monthly allowance */
  printf("Salary after tax: £%.2f\n", *salary_after_tax); 
  printf("Your monthly allowance: £%.2f\n", *salary_after_tax/12);
  printf("Your weekly allowance: £%.2f\n", *salary_after_tax/52);
  
  return 0;
}


int main(int argc, char *argv[]) {
  float salary, salary_after_tax;
  float *salary_after_tax_ptr = &salary_after_tax;
  float *salary_ptr = &salary;  
  float taxes_paid = 0;
  float *ptr_taxes_paid = &taxes_paid;
  int errno;

  if (argc == 1) {
    printf("What are you offered? \n");
    fscanf(stdin, "%f", salary_ptr);
  } else if (argc == 2) {
    char *number = argv[1]; 
    char *end;
    *salary_ptr = strtof(number, &end);
}
  // printf("%f\n", *salary_ptr);
  errno = calc_taxes(salary_ptr, ptr_taxes_paid);
  *salary_after_tax_ptr = *salary_ptr - *ptr_taxes_paid;
  // *salary_after_tax_ptr = 25000.0;
  salary_stats(salary_after_tax_ptr);
  return 0;
}
