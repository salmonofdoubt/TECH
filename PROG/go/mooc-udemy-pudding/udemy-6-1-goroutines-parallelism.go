///////////////////////////////////////////
//// The proof is in the pudding //////////
///////////////////////////////////////////
////////// go routines ////////////////////
////////// Parallelism ////////////////////
// Concurrency: independently executing /// one process at a time ////////////
// Parallelism: simulultaneous execution // all processes at the same time ///
//////////////////////////////////////////////////////////////////////////////

package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup

func init() {
	runtime.GOMAXPROCS(runtime.NumCPU()) //use all cores (CPUs)
}

func main() {
	wg.Add(2) //as there are 2 go routines
	go foo()
	go bar()
	wg.Wait()
}

func foo() {
	for i := 0; i < 100; i++ {
		fmt.Println("Foo: ", i)
		time.Sleep(time.Duration(2 * time.Millisecond)) //demo concurrency
	}
	wg.Done()
}

func bar() {
	for i := 0; i < 100; i++ {
		fmt.Println("Bar: ", i)
		time.Sleep(time.Duration(20 * time.Millisecond))
	}
	wg.Done()
}
