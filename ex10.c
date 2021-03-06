#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv bar argv[0]
    // because argv[0] is the function name

    //general loop construct
    //for(initialiser; test; incrementer)
        //{ block of code
        // }
    for(i = 0; i < argc; i++){
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make own array of strings
    char *states[] = {
        "California", "Oregon", "Washington", "Texas", "Freedom"}; 
    int num_states = 5;

    for(i = 0; i < num_states; i++) {
        printf("state %d: is %s\n", i, states[i]); 
    }
    return 0;
}