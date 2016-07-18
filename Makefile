# make looks for the makefile in this order: GNUmakefile, makefile and Makefile
CFLAGS=-Wall -g

all: ex19

ex19: object.o

$$1: $$1.c
	cc -o $$1 $$1.c

.PHONY : clean
clean:
	rm -f ex1 ex3
