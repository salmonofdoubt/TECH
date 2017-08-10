///////////////////////////////////////
//////////// go routines //////////////
///////// Channels ////////////////////
/*
Challenge: factorials of all numbers up to 20
concurrently, in parallel
*/

package main

import (
	"fmt"
)

func main() {

	in := channelGenerator()

	f := channelTaker(in)

	for n := range f {
		fmt.Println(n)
	}
}

func channelGenerator() <-chan int {
	out := make(chan int)
	go func() {
		for i := 0; i < 20; i++ {
			out <- i
		}
		close(out)
	}()
	return out
}

func channelTaker(in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		for n := range in {
			out <- fact(n)
		}
		close(out)
	}()
	return out
}

func fact(n int) int {
	total := 1
	for i := n; i > 0; i-- {
		total *= i
	}
	return total
}
