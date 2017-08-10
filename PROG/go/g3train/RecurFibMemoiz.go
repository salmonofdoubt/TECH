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

//aux must be accessible by main() and fib()
var aux []int

func main() {
	var n int

	fmt.Println("Integer: ")
	fmt.Scan(&n)

	//done from outside the recursive func
	for i := 0; i <= n; i++ {
		aux = append(aux, -1)
	}
	aux[0] = 0
	aux[1] = 1
	fmt.Println(aux)

	fmt.Println(fib(n))
}

func fib(n int) int {

	if n <= 1 { //simplest possible scenario, return n from this subroutine
		return n
	}
	if aux[n] != -1 { //initially it will be -1
		return aux[n]
	}

	aux[n] = fib(n-1) + fib(n-2) //populate aux over time
	fmt.Println(aux)
	return aux[n]
}

/*
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
