#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char *name = "\0\0a\0\0";
    
    // first, print them out raw
    printf("numbers: %d, %d, %d, %d\n", numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name each: %c %c %c %c %c\n", name[0], name[1],
            name[2], name[3], name[4]);
    // a string is an array of characters - hence the format specifier %s
    printf("name: %s\n", name);

    //setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    printf("##############\nNumbers all set up now\n");
    
    // setup the name
    name[0] = 'P';
    name[1] = 'e';
    name[2] = 't';
    name[3] = 'r';
    name[4] = '\0';
    printf("##############\n\nName all set up now\n\n");   

    // then print them out initialised
    printf("numbers: %d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2],
            numbers[3]);
    printf("name by character: %c %c %c %c %c\n", name[0], name[1], 
                    name[2], name[3], name[4]);
    printf("%d\n", name);
    //print them like a string
    printf("name: %s\n", name);

    // another way to use name - more common to assign values to strings
    // use this - this is an idiomatic C convention
    char *another = "Petr";
    
    printf("another:%s\n", another);

    printf("another by character: %c %c %c %c\n", another[0], another[1], another[2],
            another[3]);


// doing extras

    return 0;
}
