#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 
* How many, not necessarily distinct, values of  nCr, 
for 1 ≤ n ≤ 100, are greater than one-million?

make a factorial function
make a nCr function 
brute force through the options

Compile:
gcc -lm euler53.c -o euler53

Run: 
./euler53

*/

int fact(unsigned int num, long *fact_of_number)
{
    /*Takes:
    *       a number 
            pointer to factorial of number

    *   return 0 if all goes well 
            and changes the value at pointer address to factorial of number
    */
    if (num < 0)
    {
        printf("Error - negative numbers don't have a factorial\n");
        return 1;
    }
    *fact_of_number = 1;
    for (int i = 2; i <= num; i++)
    {
        *fact_of_number *= i;
    }

    return 0;
}

int nCr(int n, int r, long *res_ptr)
{
    /* Takes pointer to N and r
    return 0 if number successfully assigned to res_ptr
    */
    if (r > n)
    {
        printf("Error. Cannot calculate the value\n");
        return 1;
    }

    long *n_fact = malloc(sizeof(long));
    long *r_fact = malloc(sizeof(long));
    long *n_r_fact = malloc(sizeof(long));

    fact(n, n_fact);
    fact(r, r_fact);
    fact((n - r), n_r_fact);
    *res_ptr = (*n_fact)/((*r_fact)*(*n_r_fact));
    
    free(n_fact);
    free(r_fact);
    free(n_r_fact);
    return 0;
}

int simulate_nCr(int n, int upper_limit) {
    /* Given N - top number, return the number of nCr values above the upper_limit */
    int counter = 0;
    long *nCr_value_ptr = malloc(sizeof(long));
    for (int num = 0; num <= n; num++)
    {
        printf("Now looking at %d\n", num);
        for (int r = 0; r <= num/2; r++) {
            nCr(num, r, nCr_value_ptr);
            printf("%ld\n", *nCr_value_ptr);
            if (*nCr_value_ptr > upper_limit) {
                counter += 1;
            }
        }
    }
    free(nCr_value_ptr);
    return counter;
}

int main(int argc, char *argv[])
{
    int N = 50;
    int res;
    int upper_limit = 5;
    res = simulate_nCr(N, upper_limit);
    printf("%d\n", res); 

    return 0;
}

/* 
int main(int argc, char *argv[]) {
    // Compile as normal and use as below
    // ./euler53 <N_to_factorialise>
    if (argc != 2) {
        printf("Error! Use ./euler53 <N_to_factorialise>\n");
        return 1;
    }
    n = atoi(argv[1]);
    long *res;
    fact(n, res);
    printf("%ld\n", *res);
    return 0;
}
*/ 