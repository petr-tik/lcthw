CC=gcc
CFLAGS=-Wall
DEPS=salary_calc.c
OBJ = salary_calc.o 


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

salary_calc: $(OBJ)
	gcc $(CFLAGS) $(DEPS) $@ $^
