#include <stdio.h>
#include <ctype.h>

// forward declaration
int can_print_it(char ch); // a func that takes a char and returns int
void print_letters(char arg[]); // func takes char array (string), returns nothing

void print_arguments(int argc, char *argv[])
{
    // int i = 0;
    for(int i = 0; i < argc; i++)
    {
        print_letters(argv[i]);
    }
}

void print_letters(char arg[]){
    int i = 0;
    for(i = 0; arg[i] != '\0'; i++){
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