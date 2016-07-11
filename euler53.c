#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 
* How many, not necessarily distinct, values of  nCr, 
for 1 ≤ n ≤ 100, are greater than one-million?

make a factorial function
make a nCr function 
brute force through the options

*/

int fact(unsigned int *num_ptr, long *fact_of_number)
{
    /*Takes:
    *       pointer to a number 
            pointer to factorial of number
    *   return 0 if all goes well
    */
    int number = *num_ptr;
    if ((number) < 0)
    {
        printf("Error - negative numbers don't have a factorial\n");
        return 1;
    }
    for (int i = 2; i < number + 1; i++)
    {
        *fact_of_number *= i;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    unsigned int number = atoi(argv[1]);
    unsigned int *num_ptr = &number;
    long fact_of_number = 1;
    long *ptr_to_fact = &fact_of_number;
    int errno = fact(num_ptr, ptr_to_fact);
    if (errno == 0)
    {
        printf("%ld\n", *ptr_to_fact);
    } 
    return 0;
}