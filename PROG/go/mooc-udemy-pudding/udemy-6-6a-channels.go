////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/// Channels, range super important ///
///////////////////////////////////////
/// N(funcs)-to-(channel) //////////
////////////////////////////////////

package main

import (
	"fmt"
	"sync"
)

// 2 independent go routines write to the same channel c
// race condition, WaitGroup used incorrectly

func main() {
	c := make(chan int)

	var wg sync.WaitGroup // race cond being all three routines write to it

	go func() {
		wg.Add(1)
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		wg.Done()
	}()

	go func() {
		wg.Add(1)
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		wg.Done()
	}()

	go func() {
		wg.Wait()
		close(c)
	}()

	for n := range c {
		fmt.Println(n)
	}
}
