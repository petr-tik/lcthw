#include <stdio.h>

int factorial(int upper);

int factorial(int upper){
    long product = 1;
    int i;
    for(i = 2; i <= upper; i++){
        product *= i;
    }
    return product;
}


int main(int argc, char *argv[])
{
    int var = 16;
    printf("The factorial of %d is %d\n", var, factorial(var));
    return 0;
}