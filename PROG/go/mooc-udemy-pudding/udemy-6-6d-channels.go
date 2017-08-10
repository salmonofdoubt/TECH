////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////// Channels, perfects s ///////
////////////////////////////////////
/// N(funcs)-to-1(channel) /////////
////////////////////////////////////

package main

import (
	"fmt"
)

func main() {

	n := 10
	c := make(chan int)
	cdone := make(chan bool)

	for i := 0; i < n; i++ {
		go func() {
			for i := 0; i < n; i++ {
				c <- i //put i onto the channel. The code stops here. Relay racers.
			}
			cdone <- true
		}()
	}

	go func() {
		for i := 0; i < n; i++ {
			<-cdone
		}
		close(c)
	}()

	for n := range c { //after the 3 routines are done, range drains the channel
		fmt.Println(n)
	}
}
