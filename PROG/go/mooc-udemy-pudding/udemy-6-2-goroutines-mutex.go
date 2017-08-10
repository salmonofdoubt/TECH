////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////
////////// go routines /////////////
////// mutex mutually exclusive ////

package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup
var counter int
var mutex sync.Mutex

func init() {
	runtime.GOMAXPROCS(runtime.NumCPU()) //use all cores (CPUs)
}

func main() {
	wg.Add(2) //as there are 2 go routines
	go incrementor("Foo:")
	go incrementor("Bar:")
	wg.Wait()
	fmt.Println("Final Counter:", counter)
}

func incrementor(s string) {
	for i := 0; i < 20; i++ {
		time.Sleep(time.Duration(rand.Intn(20)) * time.Millisecond)
		/// no other proc can get to inside this
		{
			mutex.Lock()
			/// next 3 lines would cause data race since two routines may access it
			x := counter
			x++
			counter = x
			//counter++
			fmt.Println(s, i, "Counter:", counter)
			/// release the lock
			mutex.Unlock()
		}
	}
	wg.Done()
}
