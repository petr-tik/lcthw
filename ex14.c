#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declaration
// int can_print_it(char ch); // a func that takes a char and returns int
void print_letters(int length, char arg[]); // func takes char array (string), returns nothing

void print_arguments(int argc, char *argv[])
{
    // int i = 0;
    for(int i = 1; i < argc; i++)
    {
        int length = strlen(argv[i]);
        print_letters(length, argv[i]);
    }
}

void print_letters(int length, char arg[]){
    int i = 0;
    for(i = 0; i < length; i++){
        char ch = arg[i];
        if(isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d in ascii ", ch, ch);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}