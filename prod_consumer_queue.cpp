#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

/*

a number of threads create work for a consumer. The consumer should block on the
queue when there is no work, the workers should safely add work to the queue
then wake the consumer.

work will be reading a string like `+ 5 6 7` or `/ 8 4` and returning the
result.

*/

enum sign_code {
	eAddition,
	eSubstraction,
	eMultiplication,
	eDivision,
};

sign_code char_to_signcode(const char &sign)
{

	if (sign == '+') {
		return eAddition;
	} else if (sign == '-') {
		return eSubstraction;
	} else if (sign == '*') {
		return eMultiplication;
	} else if (sign == '/') {
		return eDivision;
	}
}
std::vector<int> string_to_ints(const std::string &string_no_sign)
{
	/*
	Given a string without a sign, return a vector of ints inside
	the
	string.
	`5 2 14 67` -> [5, 2, 14, 67]
	*/
	std::string string_so_far;
	std::vector<int> result;
	for (auto char_in_string : string_no_sign) {
		if (&char_in_string == " ") {
			result.push_back(stoi(string_so_far));
			string_so_far.clear();
		} else {
			string_so_far.push_back(char_in_string);
		}
	}
}

int operation_to_result(const std::string rpn_expression)
{
	/*
	  Safe to assume input is correct i.e. `/ 8 4` or  `+ 5 6 7`  is
	  possible, `/ 8 4 5 3` isn't.
      */
	int result = 0;
	const char &sign = rpn_expression[0];
	std::vector<int> v =
	    string_to_ints(rpn_expression.substr(2, rpn_expression.size()));

	switch (char_to_signcode(sign)) {
	case eAddition:
		return std::accumulate(v.begin(), v.end(), 0);
	case eMultiplication:
		return std::accumulate(v.begin(), v.end(), 1,
				       std::multiplies<int>());
	case eDivision:
		return -1;
	case eSubstraction:
		return -1;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int res;
	const std::string &ex = "+ 5 2";
	res = operation_to_result(ex);
	std::cout << res << "\n";
	return res;
}
