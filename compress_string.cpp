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

string compress(const string &to_compress)
{
	/*
	  Takes a reference (not pointer) to a const string, which makes the
	  string immutable. Creates a counter (init at 0) and a stringstream,
	  which is initialised with the first character of the string. After
	  that, iterate over the given string compare it to the last char in the
	  stringstream. If the char is different, append the counter of the
	  previous char, reset counter to 1 and append the new char.

	 */
	stringstream ss;
	int counter = 0;
	ss << to_compress.at(0);
	for (char c : to_compress) {
		if (ss.str().back() == c) {
			++counter;
		} else {
			// new element - add to letters and set its count to 1
			ss << counter;
			counter = 1;
			ss << c;
		}
	}

	return ss.str();
}

int main(int argc, char *argv[])
{
	string to_compress;
	if (argc == 2) {
		to_compress = argv[1];

	} else {
		cout << "ERROR. Only 2 arguments accepted" << endl;
		return 1;
	}

	string res = compress(to_compress);
	cout << res << endl;

	return 0;
}
