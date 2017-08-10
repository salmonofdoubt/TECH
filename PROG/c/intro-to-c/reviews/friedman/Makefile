CC=gcc
CFLAGS=-O0 -Wall

simple_find: simple_find.o main.o

simple_find.o: simple_find.h simple_find.c

main.o: simple_find.h main.c

clean: simple_find.o main.o simple_find
	rm -f simple_find.o main.o simple_find
