#include <algorithm>
#include <condition_variable> // std::condition_variable
#include <cstring>
#include <iostream>
#include <mutex>
#include <numeric>
#include <queue>
#include <stdlib.h>
#include <sstream>
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

std::mutex mx;
std::condition_variable cv;
std::queue<std::string> queue;

void producer(int n)
{
	for (int i = 0; i < n; ++i) {
		std::lock_guard<std::mutex> lk(mx);
		std::string ex = gen_example_string().str();

		queue.push(ex);
		std::cout << "pushing "
			  << "(" << ex << ")"
			  << " to the queue\n";
	}
	cv.notify_all();
}

bool is_queue_empty(std::queue<std::string> q) { return q.empty(); }

void consumer()
{
	while (true) {
		std::unique_lock<std::mutex> lk(mx);
		cv.wait(lk, [] { return !queue.empty(); });
		while (!queue.empty()) {
			std::string consumed = queue.front();
			std::cout << "consumed " << consumed
				  << " from the queue\n";
			queue.pop();
			std::cout << operation_to_result(consumed) << "\n";
		}
		return;
	}
}

int main(int argc, char *argv[])
{

	// std::mutex mx;
	// std::condition_variable cv;
	// std::queue<std::string> queue;

	std::thread t1(producer, 20);
	std::thread t2(consumer);
	t2.join();
	t1.join();

	return 0;
}
