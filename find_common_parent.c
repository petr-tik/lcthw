#include <stdio.h>
#include <stdlib.h>
/*

Given a root of a binary search tree and 2 values.

Return the value of the ancestor between the 2 values. If they don't share an
ancestor, return null

Normal compilation:

$ clang find_common_parent.c -o find_common_parent

with gdb
$ clang -g find_common_parent.c -o find_common_parent



*/

// definitions

int generate_random_between_l_n_r(int l, int r);

typedef struct node {
	int value;
	struct node *left_child;
	struct node *right_child;
} node_t;

node_t *create_node(int value)
{
	// given a value, allocs a node_t with that value and returns a pointer
	// to it
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	return new_node;
}

node_t *make_tree_manual()
{
	node_t *root = create_node(20);
	int res;
	node_t *first_r_child = create_node(10);
	first_r_child->right_child = create_node(5);
	first_r_child->left_child = create_node(15);
	root->right_child = first_r_child;

	node_t *first_l_child = create_node(30);
	first_l_child->left_child = create_node(35);
	first_l_child->right_child = create_node(25);
	root->left_child = first_l_child;
	return root;
}

int main(int argc, char *argv[])
{
	printf("Hello world\n");
	node_t *root = make_tree_manual();

	return 0;
}
