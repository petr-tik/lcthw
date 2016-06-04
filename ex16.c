#include <stdio.h> // normal IO read/write funcs
#include <assert.h> // gives assert func
#include <stdlib.h> // provides free, malloc funcs
#include <string.h> // gives strdup func

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL); // check the pointer isn't unset or invalid 
    // if assert returns false, aborts the programme

    who->name = strdup(name); // copy the string to make sure it's owned by the struct
    who->age = age;
    who->height = height;
    who->weight = weight;
    // x->y = z
    // sets the Y parameter of the X struct to the value Z

    return who;
}

void Person_destroy(struct Person *who){
    assert(who != NULL);
    // given a pointer, free memory at that pointer
    // if ptr is NULL, no operation is performed
    free(who->name);
    // free(who);
    // running free on already freed pointer causes an error
    // *** Error in `./ex16': double free or corruption (fasttop): 0x0000000001f3c010 ***
}

// func returns nothing, takes a Person struct as argument and prints its attributes
void Person_print(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("Age: %d\n", who->age);
    printf("Height: %d\n", who->height);
    printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make 2 people
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Underwood", 20, 72, 180);
    // using a predefined Person_create func
    // make a pointer of the type struct using to the Person struct with given initialisation values

    // print them out and their memory locations
    printf("Joe's memory address is: %p\n", joe);
    Person_print(joe);

    printf("Frank's memory address is: %p\n", frank);
    Person_print(frank);

    // make everyone 20 years older and print again
    joe->age += 20;
    joe->height -= 2; //became shorter too
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both to leave it clean
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}