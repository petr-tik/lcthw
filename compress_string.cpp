#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
  Given a pointer to a string to compress
  return a string in the form:
  <char><char_count> of all the characters in the to_compress string
  eg. aaabbcccdff -> a3b2c3d1f2


  $$$ clang++-3.7 -std=c++11 compress_string.cpp -o compress_string
  $$$ ./compress_string <string_to_compress>

  for debugging
  $$$ clang++-3.7 -std=c++11 -g -D_GLIBCXX_DEBUG compress_string.cpp -o
  compress_string
  $$$ gdb ./compress_string
  $$$ (gdb) start <string_to_compress>

*/

std::string compress(const std::string &to_compress)
{
	int count = 0;
	char letter = 0; // not a letter

	std::stringstream ss;
	for (char c : to_compress) {
		if (c == letter) {
			++count;
		} else {
			if (count >= 1) {
				ss << count;
			}
			letter = c;
			count = 1;
			ss << c;
		}
	}
	ss << count; // add the count for the last char
	return ss.str();
}

int main(int argc, char *argv[])
{
	std::string to_compress;
	if (argc == 2) {
		to_compress = argv[1];
		std::cout << "let's compress some shizz\n";
	} else {
		std::cerr << "ERROR. Only 2 arguments accepted\n";
		return 1;
	}

	std::string res = compress(to_compress);
	std::cout << res << '\n';
	return 0;
}
