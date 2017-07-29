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

g++ -std=c++11 -g prod_consumer_queue.cpp -o prod

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
	string_so_far.clear();
	std::vector<int> result(0);
	for (auto char_in_string : string_no_sign) {
		if (char_in_string == ' ') {
			result.push_back(stoi(string_so_far));
			string_so_far.clear();
		} else {
			string_so_far.push_back(char_in_string);
		}
	}

	result.push_back(stoi(string_so_far));
	return result;
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
		return v[0] / v[1];
	case eSubstraction:
		return v[0] - std::accumulate(v.begin() + 1, v.end(), 0);
	}
	return result;
}

std::stringstream gen_example_string()
{
	std::stringstream example_string;
	char signs[] = {'+', '-', '*', '/'};
	char random_sign = signs[std::rand() % 4];
	example_string << random_sign << " ";
	int rand_num1, rand_num2;
	rand_num1 = std::rand() % 20 + 1;
	rand_num2 = std::rand() % 20 + 1;

	example_string << rand_num1 << " ";
	example_string << rand_num2;

	return example_string;
}

int main(int argc, char *argv[])
{
	int res, res2, res3, res4;
	const std::string &ex = "+ 5 2 7 8";
	const std::string &ex2 = "* 10 3 4";
	const std::string &ex3 = "/ 8 4";
	const std::string &ex4 = "- 25 5 11";

	res = operation_to_result(ex);
	std::cout << "(" << ex << ")"
		  << " = " << res << "\n";
	res2 = operation_to_result(ex2);
	std::cout << "(" << ex2 << ")"
		  << " = " << res2 << "\n";
	res3 = operation_to_result(ex3);
	std::cout << "(" << ex3 << ")"
		  << " = " << res3 << "\n";
	res4 = operation_to_result(ex4);
	std::cout << "(" << ex4 << ")"
		  << " = " << res4 << "\n";

	for (int idx = 0; idx < 5; ++idx) {
		std::string ex = gen_example_string().str();
		res = operation_to_result(ex);

		std::cout << "(" << ex << ")"
			  << " = " << res << "\n";
	}

	return res;
}
