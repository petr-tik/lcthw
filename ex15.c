#include <stdio.h>

int main(int argc, char *argv[])
{
    // create 2 arrays we care about
    int ages[] = {23, 43, 12, 89, 12};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages 
    // length of array with equal number of items will differ in different machines
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for(int i = 0; i < count; i++)
    {
       printf("%s is %d years alive\n", names[i], ages[i]);
    }

    printf("\n----------\n");

    // setup the pointers to the beginning of arrays
    int *cur_age = ages;
    
    char **cur_name = names;
    printf("%p stores an int of %d \n", &cur_age, *cur_age);


    // 2nd method - using pointers
    for(i = 0; i < count; i++){
        printf("%s is %d years old\n", *(cur_name+i), *(cur_age+i));
        //printf("The age '%d' is stored in memory at %p\n", *(cur_age + i), &(cur_age+i));
    }
    // pointer is just a memory address, which you can loop over if you add the size of element in bytes

    printf("\n-------------\n");

    // 3rd method - pointers are just arrays
    for(i = 0; i < count; i++){
        printf("%s is %d years old again\n", cur_name[i], cur_age[i]);
    }

    printf("\n------------\n");

    // 4th method with pointers in a complicated way
    for(cur_name = names, cur_age = ages; 
        (cur_age - ages) < count;
        cur_name++, cur_age++)
    {
        printf("%s has lived %d years so far \n", *cur_name, *cur_age);
    }
    return 0;
}

// Don't continue until you've written down what you think a pointer does.

// afaik
// a pointer of a particular type (int, char, whatever) defines the beginning of a block of memory 
// allocated for that data type (ints, chars)