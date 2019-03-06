C = gcc
CFLAGS = -o2

find: find.o main.o
	gcc -o find find.o main.o
find.o: find.h find.c
	gcc -c -o find.o find.c
main.o: find.h main.c
	gcc -c -o main.o main.c
clean:
	rm -f *.o find

