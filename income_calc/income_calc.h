#ifndef _INCOME_CALC_H
#define _INCOME_CALC_H 

// length of taxrates and salary_limits array. 
int NUM_TAXES = 10;

typedef struct tax_t {
  float TAXRATES[NUM_TAXES];
  int SALARY_LIMITS[NUM_TAXES];
  char SIGN[3];
} tax_t;


tax_t UK = {.TAXRATES = {0, 20, 40, 45}, 
            .SALARY_LIMITS = {0, 11000, 43000, 150000},
            .SIGN = "£"};

tax_t UK_NI = {.TAXRATES = {0, 12, 2},
               .SALARY_LIMITS = {0, 8064, 43000},
               .SIGN = ""};

tax_t California = {.TAXRATES = {1, 2, 4, 6, 8, 9.3, 10.3, 11.3, 12.3},
                    .SALARY_LIMITS = {0, 7850, 18610, 29372, 40773, 
                                   51350, 263222, 315866, 526443, 1000000},
                    .SIGN = "$"};

tax_t Russia = {.TAXRATES = {13},
                .SALARY_LIMITS = {100000000},
                .SIGN = "RUB"};

/* tax_t Seattle = {.TAXRATES = {},
                         .SALARY_LIMITS = {},
                         .SIGN = "$"};

tax_t NYC
*/

int calc_taxes(float *salary_ptr, float *taxes_paid, tax_t tax_rules);

int print_salary_stats(float *salary_after_tax, tax_t country);

int UK_full(float *salary_ptr, float *taxes_paid);

int Cali_full(float *salary_ptr, float *taxes_paid, int *married);

int NYC_full(float *salary_ptr, float *taxes_paid, int *married);

#endif
