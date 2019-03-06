////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////// Channels ///////////////////
////// Pipelines refactored ////////

package main

import (
	"fmt"
)

func main() {
	//set up a pipeline
	//c := gen(4, 5, 6)
	//out := sq(c)

	for n := range sq(gen(2, 3, 4, 5)) {
		//consume output
		fmt.Println(n)
	}
}

func gen(nums ...int) <-chan int { //variadic
	out := make(chan int)
	go func() {
		for _, n := range nums {
			out <- n
		}
		close(out)
	}()
	return out
}

func sq(in <-chan int) chan int {
	out := make(chan int)
	go func() {
		for n := range in {
			out <- n * n
		}
		close(out)
	}()
	return out
}
