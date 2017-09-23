#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Trie implementation to build a compact prefix-tree and store dictionaries.

Supports English alphabet, hence number of letters

clang trie.c -o trie && ./trie
clang -g -std=c99 -Wall trie.c -o trie


*/

#define LETTERS 26 // english by default

typedef struct trie_node_t {
	struct trie_node_t *children[LETTERS];
	char letter;  // store the letter
	char is_word; // if sequence up to now is a word - set to 1, else 0
} trie_node_t;

#define trie_node_size sizeof(trie_node_t)

int char_to_ascii(char letter)
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
	trie_node_t *new_node = malloc(trie_node_size);
	if (new_node) {
		// avoid accessing null pointer
		new_node->is_word = 0;
		new_node->letter = letter;
	}
	return new_node;
}

void add_to_trie(trie_node_t *root, const char *word)
{
	/*
	Iterative implementation of the add_to_trie method
	 */

	trie_node_t *cur = root;
	for (int idx_in_word = 0; idx_in_word < strlen(word); ++idx_in_word) {
		char letter = word[idx_in_word];
		int idx = char_to_ascii(letter);
		if (!(cur->children[idx])) {
			cur->children[idx] = add_node(letter);
		}
		cur = cur->children[idx];
	}
	// last letter needs to carry 1
	cur->is_word = 1;
	return;
}

void free_trie(trie_node_t *root)
{
	for (int child_idx = 0; child_idx < LETTERS; child_idx++) {
		trie_node_t *child = root->children[child_idx];
		if (child) {
			free_trie(child);
		}
	}
	free(root);
}

int has_children(trie_node_t *parent)
{
	for (int idx = 0; idx < LETTERS; ++idx) {
		if (parent->children[idx]) {
			return 1;
		}
	}
	return 0;
}

void _delete_word(trie_node_t *root, const char *word, int idx_in_word)
{
	if (idx_in_word != strlen(word)) {
		char letter = word[idx_in_word];
		int idx = char_to_ascii(letter);
		trie_node_t *next = root->children[idx];
		if (next)
			_delete_word(next, word, ++idx_in_word);
	}
	if (idx_in_word == strlen(word) && has_children(root)) {
		root->is_word = 0;
		return;
	} else
		free(root);
}

void delete_word(trie_node_t *root, const char *word)
{
	/* traverses the trie down letter-by-letter.

	 */
	char first_actual_letter = word[0];
	int idx = char_to_ascii(first_actual_letter);
	trie_node_t *next = root->children[idx];
	_delete_word(next, word, 1);
}

int is_word_in_trie(trie_node_t *root, const char *word)
{
	/* Given a word and the root of a dictionary trie, returns 1 if
	 * word is
	 * in the trie, else - 0 */
	int idx = 0;
	trie_node_t *cur = root;
	while (idx < strlen(word)) {
		if (!cur)
			return 0;
		char letter = word[idx];
		if (idx == strlen(word))
			return cur->is_word;
		cur = cur->children[char_to_ascii(letter)];
		idx++;
	}
	return (cur->is_word) ? 1 : 0;
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

	char word1[] = "hello";
	char word2[] = "worldie";
	add_to_trie(head, word1);
	add_to_trie(head, word2);
	printf("%s is/not in trie: %d\n", word1, is_word_in_trie(head, word1));
	printf("%s is/not in trie: %d\n", word2, is_word_in_trie(head, word2));
	delete_word(head, "worldie");
	free_trie(head);
	return 0;
}
