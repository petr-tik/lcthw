#ifndef _SALARY_CALC_H
#define _SALARY_CALC_H 

enum TAX_REGIME {UK, California, Seattle, NYC, Russia};

typedef struct COUNTRY_RULES {
  float TAXRATES[10];
  float SALARY_LIMITS[10];
} COUNTRY_RULES;

struct TAX_REGIMES {
  COUNTRY_RULES UK = {.TAXRATES = {0, 20, 40, 45}, 
                      .SALARY_LIMITS = {0, 11000, 43000, 150000}};
  COUNTRY_RULES California = {.TAXRATES = {1, 2, 4, 6, 8, 9.3, 10.3, 11.3, 12.3},
                              .SALARY_LIMITS = {0, 7850, 18610, 29372, 40773, 
                                                51350, 263222, 315866, 526443, 
                                                1000000};}
  COUNTRY_RULES Russia = {.TAXRATES = {13},
                          .SALARY_LIMITS = {100000000};}

} TAX_REGIMES;

int calc_taxes(float *salary_ptr, float *taxes_paid);

int salary_stats(float *salary_after_tax);

const char *argp_program_version = "Salary Calculator. Version 0.1";

#endif
