#include <stdio.h>
#include <stdlib.h>

// Find the smallest positive integer, x, 
// such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.


int num_to_dig(int *number, int *digits)
{
    // given a number, return a list of digit counts
    // return array of length 10, where 
    // array[idx] = count for idx in range(0,9)
    
    while(*number) {
        int idx = (*number % 10);
        digits[idx] += 1;
        *number /= 10;
    };
    return 0;
}

// int compare_numbers(int *num1, int *num2)
// {
//     int *digits1[10] = num_to_dig(*num1);
//     int *digits2[10] = num_to_dig(*num2);
//     for (int mult = 2; mult < 7; mult++)
//     {
//         for (int idx = 0; idx < 10; ++idx)
//         {
//         if (*digits1[idx] != *digits2[idx])
//         {
//             return 1;
//         }
//     }
//     }
//     return 0;
// }


int main(int argc, char argv[])
{
    int *number;
    *number = 123;
    int *digits = calloc(10, sizeof(int));
    num_to_dig(number, digits);
    for (int i = 0; i < 10; i++)
    {   
        int val = digits[i];
        printf("%d\n", val);
    }
    free(digits);
}

// design

// num_to_dig - converts number to array of digit counts
// main - generate int, for each int, check if 2x, 3x, 4x, 5x and 6x consist of the same digits