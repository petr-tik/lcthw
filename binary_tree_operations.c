#include <stdio.h>
#include <stdlib.h>
/*

Given a root of a binary search tree and 2 values.

Return the value of the ancestor between the 2 values. If they don't share an
ancestor, return null

Normal compilation:

$ clang binary_tree_operations.c -o bst_ops

with gdb
$ clang -g binary_tree_operations.c -o bst_ops

*/

// definitions

int generate_random_between_l_n_r(int l, int r);

// node struct and typedef

typedef struct node {
	int value;
	// children are from parent's POV - left is greater, right is smaller
	struct node *left_child;
	struct node *right_child;
} node_t;

node_t *create_node(int value)
{
	// given a value, allocs a node_t with that value and returns a pointer
	// to it
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node) {
		new_node->value = value;
	}
	return new_node;
}

node_t *make_tree_manual()
{
	/*
	  Draws this BST for testing

		  20
		/   \
	       /     \
	      /       \
	     /         \
	    10         30
	   /   \      /  \
	  /     \    /    \
	 5      15  25    35

	*/

	node_t *root = create_node(20);
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

int depth_recur(node_t *root, int depth)
{
	if (!root)
		return depth;
	int new_depth = depth + 1;
	int right_depth = depth_recur(root->right_child, new_depth);
	int left_depth = depth_recur(root->left_child, new_depth);
	return right_depth > left_depth ? right_depth : left_depth;
}

int max_tree_depth(node_t *root) { return depth_recur(root, 0); }

int test_max_tree_depth()
{

	node_t *root = make_tree_manual();
	node_t *only_root = create_node(5);
	printf("Expected: 3. Depth of tree: %d\n", max_tree_depth(root));
	printf("Expected: 0. Depth of tree: %d\n", max_tree_depth(only_root));
	return 0;
}

void in_order_print(node_t *root)
{
	if (root) {
		in_order_print(root->right_child);
		printf("%d ", root->value);
		in_order_print(root->left_child);
	}
}

void test_in_order()
{
	node_t *root = make_tree_manual();
	in_order_print(root);
	printf("\n");
}

void post_order_print(node_t *root)
{
	if (root) {
		post_order_print(root->right_child);
		post_order_print(root->left_child);
		printf("%d ", root->value);
	}
}

void test_post_order()
{
	node_t *root = make_tree_manual();
	post_order_print(root);
	printf("\n");
}

void pre_order_print(node_t *root)
{
	if (root) {
		printf("%d ", root->value);
		pre_order_print(root->right_child);
		pre_order_print(root->left_child);
	}
}

void test_pre_order()
{
	node_t *root = make_tree_manual();
	pre_order_print(root);
	printf("\n");
}

void free_tree(node_t *root)
{
	// Given the root of the tree, free all the nodes

	if (root) {
		if (root->right_child) {
			free_tree(root->right_child);
		}
		if (root->left_child) {
			free_tree(root->left_child);
		}
		free(root);
	}
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
		if ((val1 < cur->value && cur->value < val2) ||
		    (val2 < cur->value && cur->value < val1)) {
			if (is_value_in_tree(cur, val1) &&
			    is_value_in_tree(cur, val2) == 1) {
				return cur;
			} else {
				return NULL;
			}
		} else if (val1 < cur->value && cur->value > val2) {
			cur = cur->right_child;
		} else if (val1 > cur->value && cur->value < val2) {
			cur = cur->left_child;
		}
	}
	return ret;
}

int test_find_ancestor_true()
{
	node_t *root = make_tree_manual();
	int val1, val2;
	val1 = 35;
	val2 = 25;
	node_t *res = find_common_ancestor(root, val1, val2);
	if (res) {
		return 0;
	} else {
		return 1;
	}
}

int test_find_ancestor_false()
{
	node_t *root = make_tree_manual();
	int val1, val2;
	val1 = 37;
	val2 = 25;
	node_t *res = find_common_ancestor(root, val1, val2);
	if (res) {
		free_tree(root);
		return 0;
	} else {
		free_tree(root);
		return 1;
	}
}

int find_node_in_subtree(node_t *root, int value, int depth);
int find_dist_helper(node_t *root, int from, int to, int depth_so_far);

int find_distance(node_t *root, int from, int to)
{

	/*
	   Returns the int distance between from and to nodes. If at least 1 of
	   them isn't in the tree, return -1.

	   assume from is smaller than to.
	*/
	return find_dist_helper(root, from, to, 0);
}

int find_node_in_subtree(node_t *root, int value, int depth)
{
	node_t *cur = root;
	while (cur) {

		if (value == cur->value) {
			return depth;
		} else if (value > cur->value) {
			cur = cur->left_child;
			depth++;
		} else {
			cur = cur->right_child;
			depth++;
		}
	}
	return -1;
}

int find_dist_helper(node_t *root, int from, int to, int depth_so_far)
{
	if (!root) {
		return depth_so_far;
	}
	if (root->value >= from && root->value <= to) {
		int new_depth = depth_so_far + 1;
		int right_node_depth =
		    find_node_in_subtree(root->right_child, from, new_depth);
		int left_node_depth =
		    find_node_in_subtree(root->left_child, to, new_depth);
		if (left_node_depth == -1 || right_node_depth == -1) {
			return -1;
		} else {
			return left_node_depth + right_node_depth;
		}
	}
	node_t *next;
	if (root->value > to) {
		node_t *next = root->left_child;
	}
	if (root->value < from) {
		node_t *next = root->right_child;
	}
	return find_dist_helper(next, from, to, depth_so_far);
}

int test_find_distance()
{
	node_t *root = make_tree_manual();
	int from = 5;
	int to = 35;
	int res_should_be_four = find_distance(root, from, to);
	from = 10;
	to = 30;
	int res_should_be_two = find_distance(root, from, to);

	int all_results = (res_should_be_four == 4) & (res_should_be_two == 2);
	return all_results;
}

int main(int argc, char *argv[])
{
	int res1, res2;
	res1 = test_find_ancestor_true();
	res2 = test_find_ancestor_false();

	test_find_distance();
	return 0;
}
