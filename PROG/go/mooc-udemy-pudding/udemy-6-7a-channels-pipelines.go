////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////// Channels ///////////////////
////////////////////////////////////
/// Challenge //////////////////////
////// Pipelines ///////////////////

package main

import (
	"fmt"
)

func main() {
	//set up a pipeline
	c := gen(4, 5, 6)
	out := sq(c)

	//consume output
	fmt.Println(<-out) //16
	fmt.Println(<-out) //25
	fmt.Println(<-out) //36
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
