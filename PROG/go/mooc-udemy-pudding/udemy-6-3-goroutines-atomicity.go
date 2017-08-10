////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
/////////// Atomicity //////////////

package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
	"time"
)

var wg sync.WaitGroup
var counter int64 // owh, they probably want to mute this atomically
var mutex sync.Mutex

func main() {
	wg.Add(2) //as there are 2 go routines
	go incrementor("Foo:")
	go incrementor("Bar:")
	wg.Wait()
	fmt.Println("Final Counter:", counter)
}

func incrementor(s string) {
	for i := 0; i < 20; i++ {
		time.Sleep(time.Duration(rand.Intn(3)) * time.Millisecond)
		/// race: (go run -race <file>)
		//counter++
		/// no race:
		atomic.AddInt64(&counter, 1) //atomic counter
		fmt.Println(s, i, "Counter:", counter)
	}
	wg.Done()
}
