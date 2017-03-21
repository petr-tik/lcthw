#include <array>
#include <iostream>
#include <iterator>

/*
  Rosalind stone puzzle about counting chars in a string
  http://rosalind.info/problems/dna/

  clang++ -std=c++14 -O3 count_dna.cpp -o count_dna
  ./count_dna < DNA_STRING_FILE.txt
 */

int main(int argc, char *argv[])
{
	// we know the keys, so we can hardwire them
	enum nucleotides { A, C, G, T };

	// http://en.cppreference.com/w/cpp/container/array
	std::array<int, 4> dna_char_map;
	dna_char_map.fill(0);

	// http://en.cppreference.com/w/cpp/iterator/istream_iterator
	std::istream_iterator<char> end;
	for (std::istream_iterator<char> it = std::cin; it != end; ++it) {
		switch (*it) {
		default:
			std::cerr << "bad input: " << *it << '\n';
			return -1;
		case 'A':
			++dna_char_map[A];
			break;
		case 'C':
			++dna_char_map[C];
			break;
		case 'G':
			++dna_char_map[G];
			break;
		case 'T':
			++dna_char_map[T];
			break;
		}
	}

	std::cout << dna_char_map[A] << ' ';
	std::cout << dna_char_map[C] << ' ';
	std::cout << dna_char_map[G] << ' ';
	std::cout << dna_char_map[T] << ' ';
	std::cout << '\n';

	return 0;
}
