my_find: print_dirs.o main.o
				gcc -o my_find print_dirs.o main.o

print_dirs.o : print_dirs.h main.o
				gcc -c -o print_dirs.o print_dirs.c

main.o : print_dirs.h main.c
				gcc -c -o main.o main.c
