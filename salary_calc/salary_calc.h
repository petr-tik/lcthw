#ifndef _SALARY_CALC_H
#define _SALARY_CALC_H 

// enum TAX_REGIME {UK, California, Seattle, NYC};

typedef struct COUNTRY_RULES {
  float TAXRATES[10];
  float SALARY_LIMITS[10];
} COUNTRY_RULES;

struct TAX_REGIMES {
  COUNTRY_RULES UK = {.TAXRATES = {0, 20, 40, 45}, .SALARY_LIMITS = {0, 11000, 43000, 150000}};
  COUNTRY_RULES California = {};
};

int calc_taxes(float *salary_ptr, float *taxes_paid);

int salary_stats(float *salary_after_tax);


#endif
