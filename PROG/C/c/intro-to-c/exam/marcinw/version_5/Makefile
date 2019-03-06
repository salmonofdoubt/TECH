CC = gcc
CFLAGS = -g -O2 -Wall

find: filetricks.o find.o

filetricks.o: filetricks.h filetricks.c

find.o: filetricks.h find.c

clean:
	rm -rf *.o find