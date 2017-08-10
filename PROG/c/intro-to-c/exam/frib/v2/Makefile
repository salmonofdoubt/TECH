CC=gcc
CFLAGS=-Wall -g

all:	find


find:	main.o find.o env.o

find.o: find.h find.c

main.o: find.h env.h main.c

env.o: env.h env.c

clean:
	rm *.o	find
