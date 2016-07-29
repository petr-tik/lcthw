#ifndef _SALARY_CALC_H
#define _SALARY_CALC_H 

//enum TAX_REGIME {UK, California, Seattle, NYC, Russia};

typedef struct rules_t {
  float TAXRATES[10];
  int SALARY_LIMITS[10];
} rules_t;


typedef struct country_t {
  rules_t UK;
  rules_t California;
  rules_t Russia;
} country_t; 

country_t TAX_REGIMES = {
  .UK = {.TAXRATES = {0, 20, 40, 45}, 
                             .SALARY_LIMITS = {0, 11000, 43000, 150000}},
  .California = {.TAXRATES = {1, 2, 4, 6, 8, 
                                                  9.3, 10.3, 11.3, 12.3},
                                     .SALARY_LIMITS = {0, 7850, 18610, 29372, 
                                                       40773, 51350, 263222, 
                                                       315866, 526443, 1000000}},
  .Russia = {.TAXRATES = {13},
                                 .SALARY_LIMITS = {100000000}}
};

int calc_taxes(float *salary_ptr, float *taxes_paid);

int salary_stats(float *salary_after_tax);

const char *argp_program_version = "Salary Calculator. Version 0.1";

#endif
