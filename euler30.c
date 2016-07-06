#include <stdio.h>
#include <math.h>

// Find the sum of all the numbers that can be written
// as the sum of fifth powers of their digits.

int digit_powerer(int number, int power)
{ // given a number and a power, returns the sum of the digits 
  // taken to the power
  int sum = 0;
  int *ptr_to_sum;
  ptr_to_sum = &sum;
  int digit;
  while(number) {
    digit = number % 10;
    number /= 10;
    *ptr_to_sum += pow(digit, power);
    };

  return *ptr_to_sum;
};

int main(int argc, char *argv[])
{
   

};

