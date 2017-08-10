////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////

//always start with if, one where the fucn calls itself, one where it doesn't
//handle simples case (no recursion)

/*
The Rule is xn = xn-1 + xn-2

where:

xn is term number "n"
xn-1 is the previous term (n-1)
xn-2 is the term before that (n-2)
Example: term 9 is calculated like this:

x9	= x9-1 + x9-2
 	= x8 + x7
 	= 21 + 13
 	= 34
*/

package main

import "fmt"

func fib(n int) int {
	var res int
	if n <= 1 { //the simplest possible scenario top
		return n //returns n from this subroutine
	}
	res = fib(n-1) + fib(n-2) //two recursive calls, and repeatedly so
	return res
}

/*

3 + 2
										fib(5)
  							/     	    	  \
					fib(4) 								fib(3)
  				/    	\								/			\
   			fib(3)	fib(2)	    	fib(2)	fib(1)
				/   	\			/					/
  		/     	\   fib(1)		fib(1)
		fib(2) fib(1)
		/
	fib(1)

*/

func main() {
	var n int
	fmt.Println("Integer: ")
	fmt.Scan(&n)
	fmt.Println(fib(n))
}
