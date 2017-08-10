#gnu make utility ()
#usage: make -Dname = value (cc)
#Managing projects with GNU Make

cc = gcc
CFLAGS = -O2
filter: filter.o main.o
	gcc -o filter filter.o main.o
filter.o: filter.h filter.s
	gcc -c -o filter.s filter.c
main.o: filter.h main.c
	gcc -c -o main.o main.c
clean:
	rm -f *.o filter
