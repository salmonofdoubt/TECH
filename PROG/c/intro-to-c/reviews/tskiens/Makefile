# leczb: Minor comment: You don't have to provide the gcc commands, as GNU Make has built-in rules that deal with compiling and linking C code.

my_find: print_dirs.o main.o
				gcc -o my_find print_dirs.o main.o

# leczb: This is not correct. print_dirs.o depends on print_dirs.h and print_dirs.c, not main.o
print_dirs.o : print_dirs.h main.o
				gcc -c -o print_dirs.o print_dirs.c

main.o : print_dirs.h main.c
				gcc -c -o main.o main.c
