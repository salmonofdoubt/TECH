////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/// Channels, range super important ///
///////////////////////////////////////
/// N(funcs)-to-1(channel) //////////
////////////////////////////////////

package main

import (
	"fmt"
	"sync"
)

// 2 independent go routines write to the same channel c
// so this is better:

func main() {
	c := make(chan int)

	var wg sync.WaitGroup // race cond being all three routines write to it
	wg.Add(2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		wg.Done() //the 1st wg done
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i //put i onto the channel. The code stops here. Relay racers.
		}
		wg.Done()
	}()

	go func() {
		wg.Wait()
		close(c)
	}()

	for n := range c { //after the 3 routines are done, range drains the channel
		fmt.Println(n)
	}
}
