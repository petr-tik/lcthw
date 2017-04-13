#include <iostream>

struct my_class {
	int data_ = 0;

	my_class() { std::cout << " Invoked my_class()\n"; }

	my_class(int data) : data_(data)
	{
		std::cout << " Invoked my_class(int data)\n";
	}

	// Copy constructor
	my_class(const my_class &c) : data_(c.data_)
	{
		std::cout << " Invoked my_class(const my_class& c)\n";
	}

	// Move constructor
	my_class(my_class &&c) : data_(c.data_)
	{
		std::cout << " Invoked my_class(my_class&& c)\n";
	}

	// Copy assignment
	my_class &operator=(const my_class &c)
	{
		data_ = c.data_;
		std::cout << " Invoked operator=(const my_class& c)\n";
		return *this;
	}

	// Move assignment
	my_class &operator=(my_class &&c)
	{
		data_ = c.data_;
		std::cout << " Invoked operator=(my_class&& c)\n";
		return *this;
	}
	~my_class() { std::cout << " Invoked ~my_class()\n"; }
};

int foo(my_class c)
{
	std::cout << " Invoked foo(my_class c)\n";
	return c.data_;
}

int bar(const my_class &c)
{
	std::cout << " Invoked bar(const my_class& c)\n";
	return c.data_;
}

int bar(my_class &c)
{
	std::cout << " Invoked bar(my_class& c)\n";
	return c.data_;
}

int bar(my_class &&c)
{
	std::cout << " Invoked bar(my_class&& c)\n";
	return c.data_;
}

int main()
{
	// 0) Compile this code.
	// 1) Explain the behaviour seen when running the program.
	// 2) Modify code to invoke each of the special member functions.
	// Explain what's going on.

	std::cout << "\nInvoking my_class()\n";
	my_class m;

	std::cout << "\nInvoking foo(m)\n";
	foo(m);

	std::cout << "\nInvoking bar(m)\n";
	bar(m);
	return 0;
}
