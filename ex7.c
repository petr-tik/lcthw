#include <stdio.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;
    printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

    // original
    //  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L* 1024L * 1024L * 5024L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);
    // printf("%ld"); - prints as long decimal
    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs. \n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n", part_of_universe);

    // this is meaningless, just a demo of something weird
    unsigned char nul_byte = '\0';
// by default we use signed ints, longs, doubles etc., where the leftmost bit (0,1) defines if the number is positive or negative
// unsigned only allows you to deal with positive numbers, but operates quicker, because it efficiently uses the leftmost bit

    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);
// % is an escape char for %, so if you want to print 5%, you need to printf("5%%")
    
    char a = 'a';
    char b = 'b';
    char A = 'A';
    char B = 'B';
    int num = 5;
    int res = num * a;
    printf("a as char is %c and as num is %d\n", a, a);
    printf("b as char is %c and as num is %d\n", b, b);
    printf("A as char is %c and as num is %d\n", A, A);
    printf("When you multiply %c by %d = %d\n", a, num, res);
    printf("%c * %d = %d \n", b, num, b * num);
    // printing the decimal value of char gives you the ascii code
    return 0;

}
