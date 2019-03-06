////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////// Channels ///////////////////
/////// Challengs //////////////////

package main

import (
	"fmt"
)

func main() {
	/// 1 pushing onto and receiving/removing from a channel needs to be different
	/// routines or functions like so:
	c1 := make(chan int)

	go func() {
		c1 <- 1
	}()
	fmt.Println(<-c1, "\nFINO c1")

	/// 2 equal number of pushing/receiving. An equal For loop will do
	/// but when using range the chanhel in routine 1 needs to be closed
	c2 := make(chan int)
	n := 10

	go func() {
		for i := 0; i < n; i++ {
			c2 <- i
		}
		close(c2)
	}()

	for i := range c2 {
		fmt.Println(i)
	}
	fmt.Println("FINO c2")

	/// 3
	///
	fmt.Println(fact(4), "\nFINO fact()")
}

func fact(n int) int {
	c3 := make(chan int)
	total := 1
	go func() {
		for i := n; i > 0; i-- {
			total = total * i
			c3 <- i
		}
		close(c3)
	}()
	for r := range c3 {
		fmt.Println(r)
	}
	return total
}
