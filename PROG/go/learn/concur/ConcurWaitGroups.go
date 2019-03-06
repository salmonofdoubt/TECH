// author: abaumann@google.com
// From go/gonotes Jan 17 2017

//////// Concurrency (Part I) /////////////
////// Concurrency =!Parallelism //////////
// Concurrency: independent execution /////
// Parallelism: simulultaneous execution //
///////////////////////////////////////////

////////// TAKE AWAY //////////////////////
// small chunks of code may execute ///////
// subsequently but with big chunks, //////
// clear that both routines execute ///////
// independently //////////////////////////
///////////////////////////////////////////

package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func letter(s string) {
	for i := 0; i < 1000; i++ {
		fmt.Print(i, ":\t ", s, "\n")
	}
	//decrement the WaitGroup counter to 1.
	wg.Done()
	fmt.Println("wg.Done():", wg, "b is done") // {{} [1 0 0 0 1 0 0 0 0 0 0 0] 0}
}

func main() {

	fmt.Println("--- <main> ---")

	//set waitgroup counter
	wg.Add(2)
	fmt.Println("wg.Add(2):", wg) //{{} [0 0 0 0 2 0 0 0 0 0 0 0] 0}

	go func() {
		for i := 1000; i < 2000; i++ {
			fmt.Print(i, ":\t a \n")
		}
		//decrement the WaitGroup counter to 0
		wg.Done()
		fmt.Println("wg.Done():", wg, "a is done") // {{} [0 0 0 0 0 0 0 0 0 0 0 0] 1}
	}()

	go letter("b")

	//Wait blocks until the WaitGroup counter is zero.
	wg.Wait()
	//once it can run
	fmt.Println("wg.Wait():", wg) // {{} [0 0 0 0 0 0 0 0 0 0 0 0] 0}

	// When not using WaitGroups, a crappy way could be
	// time.Sleep(2 * time.Second)

	fmt.Println("\n --- <exit> ---")
}
