#include <iostream>

struct my_class {
	int data_ = 0;

	my_class() { std::cout << " Invoked my_class()\n"; }

	my_class(int data) : data_(data)
	{
		std::cout << " Invoked my_class(int data)\n";
	}

	// 2 types of object consutructors from a class:
	// move and copy
	// Copy takes a object of the same type and creates a new one by copying
	// the relevant data. The original object might live or not afterwards.
	// Move takes a rvalue reference (&&) to an object of the same type,
	// uses it to initialise its own data and destrors the original object
	// afterwards. That is related to the nature of rvalues and references
	// to them - they are destroyed when they leave the scope

	// Copy constructor
	my_class(const my_class &c) : data_(c.data_)
	{
		// takes a const reference to an object of type my_class and
		// constructrs a new object. Creates a copy of the existing
		// object
		std::cout << " Invoked my_class(const my_class& c). Copy "
			     "constructor.\n";
	}

	// Move constructor
	my_class(my_class &&c) : data_(c.data_)
	{
		// given a rvalue reference to an object of type my_class,
		// initialise new object's data_ variable to the value of
		// c.data_
		std::cout
		    << " Invoked my_class(my_class&& c). Move constructor.\n";
	}

	// Copy assignment
	my_class &operator=(const my_class &c)
	{
		data_ = c.data_;
		std::cout << " Invoked operator=(const my_class& c). Copy "
			     "assignment.\n";
		return *this;
	}

	// Move assignment
	my_class &operator=(my_class &&c)
	{
		data_ = c.data_;
		std::cout
		    << " Invoked operator=(my_class&& c). Move assignment.\n";
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
	// takes a const lvalue reference to my_class object. Cannot change
	// arguments
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
	//     Default constructor - done
	//     Copy Constructor - done
	//     Copy assignment operator - done
	//     Destructor
	//     Move constructor
	//     Move assignment operator

	// Explain what's going on.

	// default constructor without data,
	// creates an object of type my_class
	std::cout << "\nInvoking my_class()\n";
	my_class m;

	// only 1 kind of foo is defined above. Takes the object of type
	// my_class and returns its data. It can maliciously modify the object
	// inside the body of foo
	std::cout << "\nInvoking foo(m)\n";
	foo(m);
	/*
ignoring return value
returns
	1	Invoking foo(m)
	2	 Invoked my_class(const my_class& c)
	uses the copy constructor
	3	 Invoked foo(my_class c)

	4	 Invoked ~my_class()
	calls the default destroyer for the class, as we are leaving the scope
of the bar function
*/

	std::cout << "\nCopy assignment\n";
	my_class z;
	z = m;

	std::cout << "\nMove constructor\n";
	auto d = std::move(my_class(5));
	// std::cout << "\t\tInvoked my_class &d = m;\n";
	// d = m;
	std::cout << "\nMove assignment\n";
	my_class f;
	f = std::move(m);
	return 0;
}
