#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find the smallest positive integer, x, 
// such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.



int num_to_dig(int *number, int *digits)
{
    // takes:
    //  pointer to number
    //  pointer to array
    // fill the array with counts of each digit
    // array[idx] = count for idx in range(0,9)
    int fading_number = *number;
    while(fading_number) {
        int idx = fading_number % 10;
        digits[idx] += 1;
        fading_number /= 10;
    };
    return 0;
}

int print_digit_list(int *number)
{
    int *digits = calloc(10, sizeof(int));
    num_to_dig(number, digits);
    for (int i = 0; i < 10; i++)
    {   
        int val = digits[i];
        printf("%d\n", val);
    }
    free(digits);
}


int check_number(int *num1)
{
    /* 
    Given a number, return 0 if all its (2...6)-fold multiples 
    have same digits, otherwise 1
    */
    int *digits1 = calloc(10, sizeof(unsigned int));
    num_to_dig(num1, digits1);
    int *digits2 = calloc(10, sizeof(unsigned int));
    
    for (int mult = 2; mult < 7; mult++)
    {
        
        int num2 = (*num1) * mult;
        int *num2_ptr = &num2;
        memset(digits2, 0, sizeof(unsigned int)*10);
        num_to_dig(num2_ptr, digits2);    
        
        for (int idx = 0; idx < 10; idx++)
        {

            if (digits1[idx] != digits2[idx])
            {
                free(digits1);
                free(digits2);                
                return 1;
            }
        }
    }
    free(digits1);
    free(digits2);
    return 0;
}


int main(int argc, char argv[])
{
    int errno = -1;
    int num = 10;
    int *num_ptr = &num;
    while(*num_ptr)
    {
        if (check_number(num_ptr) == 0)
        {
            printf("%d\n", *num_ptr);
            return 0;
        }
        (*num_ptr)++; 
        // key error - first dereference the value, then increment
    }
}
    
    
// petr_tik@merluza:~/Coding/lcthw$ time ./euler52
// 142857

// real    0m0.036s
// user    0m0.032s
// sys 0m0.000s
// petr_tik@merluza:~/Coding/lcthw$ time python ../euler_project/euler52.py 
// 142857

// real    0m0.644s
// user    0m0.636s
// sys 0m0.008s

// 18 times quicker!
