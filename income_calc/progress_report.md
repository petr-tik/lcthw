## 16/8 

Reworked UK_full to have fewer if statements. If applying tax rules returns not 0, no point working further, return 1. Decision tree for UK_full is

                            return 0
                          /
              no problem /
                        /
               apply NI           
             /          \
 no problem /      error \
           /              \
apply taxes                 return 1
           \ 
     error  \   
             \    
                return 1


## 13/8

Idea to keep tax_rules structs outside the options struct. Use the location int flag to activate a branch in a ```switch``` statement, which calls the right helper function with all the business logic for that location's tax contributions, including national insurance and other charges. 

Keeps the structs nice and light, makes it easy to extend to new tax residencies by adding:
      relevant tax_rules structs
      helper func for full calculation
      a ```switch``` statement branch

## 11/8

Added the helper function for the parser - it copies the location array of chars and lowercases all upper case chars. 
-l UK, -l Uk, -l uk   - will be treated the same
-l NYc, -l NY, -l ny  - will be treated the same

This will simplify switch statement.

Thinking about struct design. Right now, I am thinking not to put the tax_rules struct inside the options, because it will make it a bloated struct. Instead, keep those structs separate and have helper funcs for each tax rule calculating the full tax contribution. 

Instead of using a bloated struct like below and initialising the substruct ```tax_t```. 
```c
typedef struct options_t {
  float amount; // mandatory
  float stock_amount; // optional 
  int married; // optional 
  char stock_quote[6]; // optional 
  short int location; // mandatory
  tax_t country;
} options_t;
```

Look inside ```options_t->location``` and call the relevant full tax calculator function for that country

Upsides:
* structs remain nice and compact
* no need for substruct nesting


Downsides: 
* Adding new countries will be a lot of manual work defining another if else branch into main, not parser. 
  * This isn't great, cos the idea is once parser is done - no more worrying about the cli args


==============================================

Changelog

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
* Rework the data structure for the parser modifies
* Make it work for UK salaries (no personal allowance if salary >150k) with parser
* Write a makefile for OSX
* Test on linux and OSX
* Add stock quote look up module
* Split the folder into a separate repo
