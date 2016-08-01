#ifndef _SALARY_CALC_H
#define _SALARY_CALC_H 

typedef enum TAX_REGIME {eUK = 0, eCalifornia = 1, eSeattle = 2, eNYC = 3, eRussia = 4} TAX_REGIME;

typedef struct rules_t {
  float TAXRATES[10];
  int SALARY_LIMITS[10];
  char SIGN[3];
} rules_t;

rules_t UK = {.TAXRATES = {0, 20, 40, 45}, 
                    .SALARY_LIMITS = {0, 11000, 43000, 150000},
                    .SIGN = "£"};
rules_t California = {.TAXRATES = {1, 2, 4, 6, 8, 9.3, 10.3, 11.3, 12.3},
                            .SALARY_LIMITS = {0, 7850, 18610, 29372, 40773, 
                                   51350, 263222, 315866, 526443, 1000000},
                            .SIGN = "$"};
rules_t Russia = {.TAXRATES = {13},
                        .SALARY_LIMITS = {100000000},
                        .SIGN = "RUB"};

/* rules_t Seattle = {.TAXRATES = {},
                         .SALARY_LIMITS = {},
                         .SIGN = "$"};

rules_t NYC
*/

int calc_taxes(float *salary_ptr, float *taxes_paid, rules_t tax_rules);

int print_salary_stats(float *salary_after_tax, rules_t country);

struct rules_t get_country(int choice);

const char *argp_program_version = "Salary Calculator. Version 0.1";

#endif
