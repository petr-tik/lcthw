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
		// takes a const reference to an object of type my_class and
		// constructrs a new object. Creates a copy of the existing
		// object
		std::cout << " Invoked my_class(const my_class& c)\n";
	}

	// Move constructor
	my_class(my_class &&c) : data_(c.data_)
	{
		// given a rvalue reference to an object of type my_class,
		// initialise new object's data_ variable to the value of
		// c.data_
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

	// class destructor, runs when the object goes out of scope.
	// any new'ed or malloc'ed memory from the class constructor should be
	// delete[] or free'd here
	~my_class() { std::cout << " Invoked ~my_class()\n"; }
};

int foo(my_class c)
{
	// takes object of type my_class as argument.
	// returns the data_ parameter of the object. Can change data if it
	// wanted to. Add the line below and it will change the object.

	// c.data_ = 5;
	std::cout << " Invoked foo(my_class c)\n";
	return c.data_;
}

int bar(const my_class &c)
{
	// takes a const reference to my_class object. Cannot change arguments
	// i.e. anything inside object. Const = read-only
	// returns the value of data_ stored inside the given class
	// if you try to compile this method with the line below uncommented.
	// You get an error
	// c.data_ = 5;
	// error: cannot assign to variable 'c' with const-qualified type
	// 'const my_class &'
	std::cout << " Invoked bar(const my_class& c)\n";
	return c.data_;
}

int bar(my_class &c)
{
	// takes a reference to an object of type my_class
	std::cout << " Invoked bar(my_class& c)\n";
	return c.data_;
}

int bar(my_class &&c)
{
	// takes an r-value reference to the object of type my_class
	std::cout << " Invoked bar(my_class&& c)\n";
	return c.data_;
}

int main()
{
	// 0) Compile this code.
	//  clang++-3.7 -std=c++11 01_construction_n_destruction.cpp -o ex01

	// 1) Explain the behaviour seen when running the program.
	// comments in each method
	// 2) Modify code to invoke each of the special member functions.

	// Special member functions are:
	//     Default constructor
	//     Copy Constructor
	//     Copy assignment operator
	//     Destructor
	//     Move constructor
	//     Move assignment operator

	// Explain what's going on.

	std::cout << "\nInvoking my_class()\n";
	my_class m;

	std::cout << "\nInvoking foo(m)\n";
	std::cout << foo(m);

	std::cout << "\nInvoking bar(m)\n";
	bar(m);

	const my_class &c = m;
	std::cout << "\nInvoking bar(c)\n";
	bar(c);
	return 0;
}
