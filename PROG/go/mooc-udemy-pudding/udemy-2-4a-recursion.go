/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////////// recursion ////////////////
/////////////////////////////////////

package main

import (
	"fmt"
)

//understand that in each recursion, individual x's are put on the stack waiting
//until they are called with a real value
//https://www.youtube.com/watch?v=ozmE8G6YKww
func fact(x int) int { // receives an int, returns an int
	if x == 0 { //the simplest possible calculation
		return 1
	}
	//comes in with x = 4
	//tries to multiply 4 * ,well, fact(3) >> dont know what fact(3) is, put it on stack
	//comes in with x = 3
	//tries to multiply 3 * ,well, fact(2) >> dont know what fact(2) is, put it on stack
	//comes in with x = 2
	//tries to multiply 2 * ,well, fact(1) >> dont know what fact(1) is, put it on stack
	//comes in with x = 1
	//tries to multiply 1 * ,well, fact(0) >> dont know what fact(0) is, put it on stack
	//comes in with x = 0
	//wait, I return 1
	//so I multiply 1 with what's on stack, so return this: 1 * 1
	//there is more stuff on stack for this routine, so return this:  1 * 1 * 2
	//there is yet more stuff on stack, so return this: 1 * 1 * 2 * 3
	//there is even more stuff on stack, so return to the calling print func
	//by making the ACTUAL calculation 1* 1 * 2 * 3 * 4 = 24
	return x * fact(x-1) //next simplest calculation
	// return x * x-1 * x-1 * above hardcoded 1
	//        3 * 2   * 1   * 1 (and that's whats returned)
}

func main() {
	fmt.Println(fact(4))
}
