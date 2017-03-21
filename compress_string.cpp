#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/*
  Given a pointer to a string to compress
  return a string in the form:
  <char><char_count> of all the characters in the to_compress string
  eg. aaabbcccdff -> a3b2c3d1f2


  clang++-3.7 -std=c++11 compress_string.cpp -o compress_string
  ./compress_string <string_to_compress>
*/

using namespace std;

string compress(string to_compress)
{
	int length = to_compress.length();
	vector<char> letters;
	vector<int> letter_counts;

	for (const char &c : to_compress) {
		if (letters.back() == c) {
			++letter_counts.back();
		} else {
			// new element - add to letters and set its count to 1
			letters.push_back(c);
			letter_counts.push_back(1);
		}
	}
	cout << letters.size() << endl;
	// walk through both vectors,
	// cast each element to char and append them to the string
	stringstream ss;

	for (int index = 0; index != letters.size(); ++index) {
		char letter = letters[index];
		char count = letter_counts[index];
		cout << letter << count;
		ss << letter << count;
	}
	return ss.str();
}

int main(int argc, char *argv[])
{
	string to_compress;
	if (argc == 2) {
		to_compress = argv[2];
		cout << "let's compress some shizz" << endl;
	} else {
		cout << "ERROR. Only 2 arguments accepted" << endl;
		return 1;
	}

	string res = compress(to_compress);
	cout << res << endl;
	return 0;
}
