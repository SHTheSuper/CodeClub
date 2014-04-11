LDFLAGS = -lm
CFLAGS = -Wall -O2

Point.o: Point.c Point.h
	gcc -c Point.c

main: main.c Point.o
	gcc -o main main.c Point.c $(LDFLAGS) $(CFLAGS)
