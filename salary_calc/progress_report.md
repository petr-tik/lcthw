Version 0.2 released so far. 

Run and compile the salary_calc.c and it should take your arguments and product basic salary stats for UK taxes and National Insurance

## Design Lessons learnt

* Need a good modular design, where the parser reads the arg string and returns a struct with relevant country, tax, income and data. After this, you shouldn't have to return to the arg string again.
* Design a good data structure that's not too clunky, but has all the necessary info.
* Still working out how to split 
* Future contributors should find it easy to add tax residencies into one file, which will add them to the command line options, but also use relevant tax_struct and rules.


## C internals

* If you are handling a pointer to a struct with an array inside it. You cannot make an assignment to an array stored with a '->' operator, instead you need to use the memcpy function, which requires arguments for: destination, source value, and number of bits of info. 
* Write and keep a good makefile - it's awesome. 
* Strings cannot be compared with a '==' operator. Use strcmp instead - it returns the number of bits different between 2 strings. If it returns 0, you have identical strings. 
* To pass argv to another function, define the function with char *argv[] and pass it directly.
* It can be useful for a function to return a return code, which will decide what to do next.


## Roadmap
* Rework the data structure the parser modifies
* Make it work for UK salaries (no personal allowance if salary >150k)
* Add stock quote look up module
