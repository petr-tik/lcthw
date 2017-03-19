#include <iostream>
#include <string>
#include <map>

/*
  Rosalind stone puzzle about counting chars in a string
  http://rosalind.info/problems/dna/

  clang++ count_dna.cpp -o count_dna
  ./count_dna <DNA_STRING>
 */

int main(int argc, char *argv[])
{
	// we know the keys, so we can hardwire them
	std::map<char, int> dna_char_map;
	dna_char_map['A'] = 0;
	dna_char_map['C'] = 0;
	dna_char_map['G'] = 0;
	dna_char_map['T'] = 0;
	std::string dna_string;
	if (argc == 2) {
		dna_string = argv[1];
	} else {
		// only works with 2 args - executable and string to analyse
		std::cout << "Error. Only works with 2 arguments" << std::endl;
		return 1;
	}
	for (char &c : dna_string) {
		// assumes it will only see one of the 4 agreed chars
		dna_char_map[c]++;
	}

	for (auto &pair : dna_char_map) {
		std::cout << pair.second << " ";
	}
	std::cout << std::endl;

	return 0;
}
