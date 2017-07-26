#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* For size_t */

/*
Recreating the list_resize method from CPython.

From the source, it shows that:
The growth pattern is:  0, 4, 8, 16, 25, 35, 46, 58, 72, 88,

clang test_list_allocs.c -o test_list && ./test_list | grep new_allocated

will print size and new_allocated size for every jump.


*/

typedef struct dummy_list_t {
	// dummy PyList - we don't care about other fields in this example
	size_t allocated;
	size_t ob_size;
} dummy_list_t;

size_t list_resize(dummy_list_t *pylist, size_t newsize)
{
	size_t allocated = pylist->allocated;
	if (allocated >= newsize && newsize >= (allocated >> 1)) {
		pylist->ob_size = newsize;
		return 0;
	}
	size_t bit_shifted_newsize = newsize >> 3;
	size_t ternary_eval = (newsize < 9 ? 3 : 6);
	printf("newsize: %zu\nbit_shifted_newsize: %zu\nternary_eval: %zu\n",
	       newsize, bit_shifted_newsize, ternary_eval);
	size_t new_allocated = newsize + bit_shifted_newsize + ternary_eval;
	printf("size: %zu\tnew_allocated: %zu\n", newsize, new_allocated);
	pylist->ob_size = newsize;
	pylist->allocated = new_allocated;
	return 0;
}

dummy_list_t *list_init()
{
	dummy_list_t *new_list = malloc(sizeof(dummy_list_t));
	return new_list;
}

int main(int argc, char *argv[])
{
	dummy_list_t *new_list = list_init();
	for (size_t size = 0; size < 10000; size++) {
		list_resize(new_list, size + 1);
	}
	return 0;
}
