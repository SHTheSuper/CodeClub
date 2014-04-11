CC=gcc
CFLAGS=-Wall -I.
DEPS=PrimeTest.h List.h
OBJ=PrimeTest.o main.o List.o
LDFLAGS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

primes: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) primes
