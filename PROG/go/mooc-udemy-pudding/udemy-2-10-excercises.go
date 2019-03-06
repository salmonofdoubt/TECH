package main

import "fmt"

func fib() func() int { //returns function which returns successive Fib numbers
	a := 0
	b := 1
	return func() int {
		a, b = b, a+b
		fmt.Println("a:", a)
		fmt.Println("b:", b)
		return a
	}
}

func main() {
	f := fib()                // Function calls are evaluated left-to-right.
	for i := 0; i < 12; i++ { // call fib() 12x, we don't pass anything
		fmt.Println("i round ", i, "\n", f())
	}
}

/*
			IN PROGRESS...

1000-digit Fibonacci number
Problem 25
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/
