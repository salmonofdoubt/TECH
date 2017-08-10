/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////////// go routines //////////////
// Channels, range super important //
/////////////////////////////////////
/// N(funcs)-to-1(channel) //////////
/////////////////////////////////////

package main

import "fmt"

// so this single go routine is now split into two, blocking each other
func main() {
	c := make(chan int) //unbuffered, vs buffered:
	//	c := make(chan int, 10)
	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		close(c)
	}()

	for n := range c {
		fmt.Println(n)
	}
}
