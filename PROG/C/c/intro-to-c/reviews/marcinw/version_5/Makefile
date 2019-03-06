CC = gcc
CFLAGS = -g -O2 -Wall -pedantic

find: filetricks.o find.o

filetricks.o: filetricks.h filetricks.c

find.o: filetricks.h find.c

clean:
	# leczb: This is a bit dangerous, as you are removing all .o files from the dir.
	# leczb: It's better to explicitely list .o files for safety reasons.
	rm -rf *.o find
