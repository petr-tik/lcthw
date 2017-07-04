#include <stdio.h>
#include <stdlib.h>
/*

Given a root of a binary search tree and 2 values.

Return the value of the ancestor between the 2 values. If they don't share an
ancestor, return null

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

int make_child(node_t *parent)
{
	// given a pointer to parent, creates a random node and makes it the
	// appropriate child. Returns 0 on success, changes parent node
	// in-place, 1 on failure
	int child_val = generate_random_between_l_n_r(10, 40);
	int parent_val = parent->value;
	node_t *child_node = create_node(child_val);
	if (child_val < parent_val) {
		parent->left_child = child_node;
		return 0;
	} else if (child_val > parent_val) {
		parent->right_child = child_node;
		return 0;
	} else { // cannot make a child with the same value
		return 1;
	}
}

int generate_random_between_l_n_r(int l, int r)
{
	int res;
	res = rand() % (r + 1 - r) + r;
	return res;
}

node_t *make_tree()
{
	node_t *root = create_node(20);
	int res1, res2;
	while ()

		res1 = make_child(root);
	res2 = make_child(root);

	return root;
}

int make_tree_of(int elements)
{
	// given the number of elements, create a tree with the number of
	// elements and return a pointer to root
	// TODO
	return 1;
}

int main(int argc, char *argv[])
{
	printf("Hello world\n");
	return 0;
}
