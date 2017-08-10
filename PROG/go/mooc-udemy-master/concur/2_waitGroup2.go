package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func main() {

	var wg sync.WaitGroup

	for i := 0; i <= 5; i++ {

		// Increment the WaitGroup counter.
		wg.Add(1)

		// Launch goroutines
		go func(i int) {
			// Decrement the counter when the goroutine completes.
			defer wg.Done()
			// Do some work
			time.Sleep(time.Duration(rand.Intn(3)) * time.Second)
			fmt.Println("Work done for ", i)
		}(i) // so run the goroutine with this number
	}

	wg.Wait() //main waited for every go routine to run
}
