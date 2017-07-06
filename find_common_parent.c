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

// node struct and typedef

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

int is_value_in_tree(node_t *root, int val)
{
	// given a value, return 1 if a node with such value is in the tree.
	// Else return 1
	node_t *cur = root;
	while (cur) {
		if (val == cur->value) {
			return 1;
		} else if (val > cur->value) {
			cur = cur->left_child;
		} else {
			cur = cur->right_child;
		}
	}
	return 0;
}

node_t *find_common_ancestor(node_t *root, int val1, int val2)
{
	node_t *ret = NULL;
	node_t *cur = root;
	while (cur) {
		if (((val1 < cur->value) && (val2 > cur->value)) ||
		    ((val1 > cur->value) && (val2 < cur->value))) {
			if (is_value_in_tree(cur, val1) &&
			    is_value_in_tree(cur, val2) == 1) {
				return cur;
			}
		} else if (val1 < cur->value && cur->value < val2) {
			cur = cur->right_child;
		} else if (val1 > cur->value && cur->value > val2) {
			cur = cur->left_child;
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	node_t *root = make_tree_manual();
	node_t *res = find_common_ancestor(root, 37, 25);
	if (res) {
		printf("%d\n", res->value);
		return 0;
	}
	printf("%p", res);

	return 0;
}
