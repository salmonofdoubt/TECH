////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/// Channels -- are communicators //
/// between go routines ////////////
/// Channels, how they block ///////
/// N(funcs)-to-1(channel) /////////
////////////////////////////////////

package main

import (
	"fmt"
	"time"
)

// so this single go routine is now split into two, blocking each other
func main() {
	c := make(chan int) //unbuffered, vs buffered:
	//	c := make(chan int, 10)
	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
	}()
	go func() {
		for {
			fmt.Println(<-c) //take number off the channel (basically give me the next)
		}
	}()
	time.Sleep(time.Second)
}
