#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Trie implementation to build a compact prefix-tree and store dictionaries.

Supports English alphabet, hence number of letters

*/

#define LETTERS 26 // english by default

typedef struct trie_node {
	struct trie_node *children[LETTERS];
	char letter;  // store the letter
	char is_word; // if sequence up to now is a word - set to 1, else 0
} trie_node_t;

int char_to_alph_index(char letter)
{

	int num = letter;
	return num - 97;
}

trie_node_t *add_node(char letter)
{
	/*
	   called when children[idx] returns a NULL pointer
	   uses the recursive property of add_to_trie. If it fails and returns a
	   NULL pointer, it will be written to the relevant index at
	   node->children[] and the recursive call will try again.
	*/
	trie_node_t *new_node = malloc(sizeof(trie_node_t));
	if (new_node) {
		// if alloc fails, cannot access NULL pointer
		new_node->letter = letter;
	}
	return new_node;
}

trie_node_t *add_to_trie(trie_node_t *root, const char *word, int idx_in_word)
{
	if (idx_in_word >= strlen(word)) {
		root->is_word = 1;
		return root;
	}
	char letter = word[idx_in_word];
	int idx = char_to_alph_index(letter);
	if (root->children[idx] != NULL) {
		++idx_in_word;
		add_to_trie(root->children[idx], word, idx_in_word);
	} else {
		root->children[idx] = add_node(letter);
		add_to_trie(root, word, idx_in_word);
	}
	return root;
}

int is_word_in_trie(trie_node_t *root, const char *word)
{
	/* Given a word and the root of a dictionary trie, returns 1 if word is
	 * in the trie, else - 0 */
}

void print_simple_trie(trie_node_t *root, trie_node_t *path_so_far[], int idx)
{
	path_so_far[idx] = root;
	if (root->is_word == 1) {
		// start from 1 to skip the H head node
		for (int path_idx = 1; path_idx <= idx; path_idx++) {
			printf("%c", path_so_far[path_idx]->letter);
		}
		printf("\n");
	}
	for (int child_idx = 0; child_idx < LETTERS; child_idx++) {
		if (root->children[child_idx]) {
			int new_idx = idx + 1;
			print_simple_trie(root->children[child_idx],
					  path_so_far, new_idx);
		}
	}
}

void build_dict()
{
	FILE *ret = popen("shuf -n 20 /usr/share/dict/british-english", "r");
	char c;
	while ((c = getc(ret)) != EOF) {
		putchar(c);
	}

	pclose(ret);
}
int main(int argc, char *argv[])
{
	trie_node_t *head = add_node('H');
	while (true) {
		printf(">");
	}

	return 0;
}
