// author: abaumann@google.com
// From go/gonotes 21/11/16, this program addresses questions 5-6

package main

import "fmt"

func main() {

	//5 Fibonacci sequence is defined as:
	// fib(0) = 0
	// fib(1) = 1
	// fib(n) = fib(n-1) + fib(n-2)
	// Write a recursive function which can find fib(n).
	fmt.Println("\n---5---")
	test := []int{5, 6, 7}
	for i := 0; i <= 2; i++ {
		fmt.Println(fib(test[i])) //5,8,13
	}

	//6
	//Write a makePrimeNumberGenerator function that generates prime numbers.
	fmt.Println("\n---6---")

}

//5
func fib(n int) int {
	var res int
	if n <= 1 { //the simplest possible scenario
		return n //returns n from this subroutine
	}
	res = fib(n-1) + fib(n-2) //so there are at least two recursive calls, and repeatedly so
	return res
}

/*
3 + 2
										fib(5)
								/								\
					fib(4)								fib(3)
  				/    	\								/			\
   			fib(3)	fib(2)	    	fib(2)	fib(1)
				/   	\			/					/
  		/     	\   fib(1)		fib(1)
		fib(2) fib(1)
		/
	fib(1)

*/

//6
func makePrimeNumberGenerator() {

}
