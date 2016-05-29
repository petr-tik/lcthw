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
    int var = 0;
    // fscanf(stdin, "%d", &var);
    // fscnaf(stdin, conversion format, pointer to intitialised variable of that type)
    // if fscanf works fine it returns 1; else return 0;
    int input_check;
    input_check = fscanf(stdin, "%d", &var);
    // check(input_check > 0, "Enter a valid number");
    printf("The factorial of %d is %d\n", var, factorial(var));
    return 0;
}