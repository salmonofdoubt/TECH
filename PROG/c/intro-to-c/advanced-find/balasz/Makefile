CC=gcc
CFLAGS=-Wall -O0 -g

find: main.o predicates.o find.o utils.o

main.o: main.c find.h predicates.h

predicates.o: predicates.c predicates.h utils.h

find.o: find.c find.h

utils.o: utils.c utils.h

clean:
	rm -f main.o predicates.o find.o utils.o find
