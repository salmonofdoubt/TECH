////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////// Channels, semaphores ///////
////////////////////////////////////
/// N(funcs)-to-1(channel) /////////
////////////////////////////////////

package main

import (
	"fmt"
)

func main() {
	c := make(chan int)
	cdone := make(chan bool)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		cdone <- true
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		cdone <- true
	}()

	//look at program flow. what if these were not in a go func??
	go func() {
		<-cdone // take value off the channel
		<-cdone
		close(c)
	}()

	for n := range c { //after the 3 routines are done, range drains the channel
		fmt.Println(n)
	}
}
