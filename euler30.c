#include <stdio.h>
#include <math.h>

// compile 
// gcc euler30.c -lm -o euler30

// Find the sum of all the numbers that can be written
// as the sum of fifth powers of their digits.

double digit_powerer(double number, int power)
{ // given a number and a power, returns the sum of the digits 
  // taken to the power
  double power_res = 0;
  double sum = 0;
  double *ptr_to_sum, *ptr_to_res;
  ptr_to_res = &power_res;
  ptr_to_sum = &sum;
  int digit;
  int int_part = (int)number;
  while(int_part) {
    digit = int_part % 10;
    int_part /= 10;
    *ptr_to_sum += pow(digit, power);
    };

  return *ptr_to_sum;
};


int main(int argc, char *argv[])
{
  double number, power, res;
  double sum = 0; // the running total
  // fscanf(stdin, "%lf", &number);
  // fscanf(stdin, "%lf", &power);
  // printf("Number: %lf to the power: %lf\n", number, power);
  
  // res = digit_powerer(number, power);
  //printf("Result: %d\n", (int)res);
  for (int num = 2; num < 1000000; num++)
  {
    double digit_power_sum;
    digit_power_sum = digit_powerer(num, 5);
    if(num == digit_power_sum)
    {
      printf("Adding %d to %lf\n", num, sum);
      sum += num;
    }
  }
  printf("%d\n", (int)sum);
  return 0;
};

// compared to its python equivalent

// petr_tik@merluza:~/Coding/lcthw$ gcc euler30.c -lm -o euler30
// petr_tik@merluza:~/Coding/lcthw$ time ./euler30
// real  0m5.925s
// user  0m5.916s
// sys 0m0.000s
// petr_tik@merluza:~/Coding/lcthw$ time python ../euler_project/euler30.py
// real  1m5.754s
// user  1m3.920s
// sys 0m0.000s
