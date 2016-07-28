#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// to run 
// gcc salary_calc.c -lm -o salary_calc
// ./salary_calc


/* 
salary | tax rate
11000  | 0%
43000  | 20%
80000  | 30%
100000 | 40%
150000 | 45%


if you earn 100,000, you pay
40% * (100,000 - 80,000) + 30% * (80,000 - 43,000) + 20%(43,000 - 11,000) = 25,500 GBP in taxes



*/

int tax_from_sum(float *salary, float *tax_rate, float *taxes_paid) {
  /* Given pointers to salary, amount of tax paid and tax_rate,
   

   */


}



int main(int argc, char *argv[]) {
  float salary;
  float *salary_ptr = &salary;  
  if (argc == 1) {
    printf("What are you offered? \n");
    fscanf(stdin, "%f", salary_ptr);
  } else if (argc == 2) {
    char *number = argv[1]; 
    char *end;
    *salary_ptr = strtof(number, &end);
}
  printf("%f\n", *salary_ptr);
  return 0;
}
