#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** same as in ex17 - die function **/
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, 
// in this case a function pointer
typedef int (*compare_cb)(int a, int b);

/**
a classic bubble sort func that uses compare_cb to do the sorting

*/
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));
    // allocates count * sizeof(int) bytes of uninitilised memory
    // returns a pointer to that memory block

    if(!target) die("memory error.");

    memcpy(target, numbers, count * sizeof(int));
    // copies count * sizeof(int) bytes from numbers (which is a memory location)
    // to target - memory we allocated previously
    // an int is 4 bytes long, so for 10 numbers, we need 10 * 4 bytes of memory

    // memcpy also returns a pointer to target, but we don't need it 

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
    // go through i integers, i times
    // compare prev with next, if in order leave, otherwise swap
    // first run will bubble the largest to the end
    // second run will bubble the 2nd largest to the end etc.
            }
        }
    }

    return target;
}

int *insert_sort(int *numbers, int count, compare_cb cmp)
{
    int start = 0;
    int end = count - 1;

    int *target = malloc(count * sizeof(int));

    if(!target) die("memory error.");

    memcpy(target, numbers, count * sizeof(int));
    // copy 

    /*
    for i = 1 to length(A)-1
    x = A[i]
    j = i - 1
    while j >= 0 and A[j] > x
        A[j+1] = A[j]
        j = j - 1
    end while
    A[j+1] = x[3]
    end for
    */

    for(int i = start + 1; i < end; i++) {
        int x = numbers[i];
        int j = i - 1;
        while(j >= 0 && numbers[j] > x) {
            numbers[j+1] = numbers[j];
            j--;
        }
    } 

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
* Used to test that we are sorting things correctly
* does the sort, print it out
*/

void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);
    // sorted is the pointer to the beginning of memory block 
    // where sorted numbers have been stored

    if(!sorted) die("Failed to sort as requested");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted); // free that block of memory
}

int main(int argc, char *argv[])
{
    if(argc < 2) die("USE like this: ex18 4 5 3 2 1");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}