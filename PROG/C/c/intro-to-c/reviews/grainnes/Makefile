CC = gcc
# leczb: This should be CFLAGS = -O2 -Wall
CFLAG = -O2

myfind : main.o visit.o
	gcc -o myfind main.o visit.o
visit.o : visit.h visit.c

main.o : main.c visit.h

clean :
	rm -f *.o myfind
