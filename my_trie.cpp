#include <string>
#include <vector>

/*
Trie implementation to build a compact prefix-tree and store dictionaries.

Supports English alphabet, hence number of letters

*/

class trie_node_t
{

	/*
	  Trie_node type, which will carry a letter and a pointer to a vector of
	  pointers to children.

	*/
      private:
	int char_to_alph_index(char letter)
	{

		int num = letter;
		return num - 97;
	}

	std::vector<trie_node_t> *children;
	char letter;  // store the letter
	char is_word; // if sequence up to now is a word - set to 1
      public:
	trie_node_t() : is_word(0), letter(''){}
	{
		std::vector<trie_node_t *> *children =
		    new std::vector<trie_node_t *>;
	}

	trie_node_t(char letter) : is_word(0), letter(letter){}
	{
		is_word = 0;
		letter = letter;
		std::vector<trie_node_t *> *children =
		    new std::vector<trie_node_t *>;
	};
	~trie_node_t(){};
};

class Trie
{
      private:
	trie_node_t &head;
	int num_elements;

      public:
	Trie() : num_elements(0), &head(trie_node_t()){}; // default constructor
	~Trie();

	int size() { return num_elements; };
	trie_node_t get_head() { return head; };
	void add(std::string word);
	int is_word_in_trie(std::string word);
};

Trie::Trie()
{
	trie_node_t &head = new trie_node_t;
	num_elements = 0;
}

Trie::~Trie()
{
	num_elements = 0;
	delete &head;
}

// Trie::Trie(std::string word)
// {
// 	Trie::Trie();
// 	Trie::add(word);
// }

void Trie::add(std::string word) {}

int main(int argc, char *argv[])
{
	while (true) {
		printf(">");
	}

	return 0;
}
