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

void clear_children(node_t *parent)
{
	// given a parent pointer, delete its children and free them
	if (parent) {
		if (parent->right_child) {
			free(parent->right_child);
		}
		if (parent->left_child) {
			free(parent->left_child);
		}
	}
}

node_t *make_tree()
{
	node_t *root = create_node(20);
	int res1, res2;
	int levels = 5;
	node_t *cur = root;
	while (levels > 0) {
		res1 = make_child(cur);
		res2 = make_child(cur);
		if (res1 || res2 == 1) {
			// if either child creation fails, delete both children
			// and try again
			clear_children(cur);
			continue;
		} else {
			levels--;
		}
	}
	return root;
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
