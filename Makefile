# make looks for the makefile in this order: GNUmakefile, makefile and Makefile
CFLAGS=-Wall -g

ex1: ex1.c
	cc -c ex1.c -o ex1

.PHONY : clean
clean:
	rm -f ex1

