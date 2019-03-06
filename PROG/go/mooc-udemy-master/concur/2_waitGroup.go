package main

import (
	"fmt"
	"sync"
)

// "sync" Package provides basic synchronization primitives such as mutual exclusion locks.
// Other than the Once and WaitGroup types, most are intended for use by low-level library routines.
// Higher-level synchronization is better done via channels and communication.

// var only so to actually see something on the screen
// https://godoc.org/sync#WaitGroup
var wg sync.WaitGroup

func main() {
	wg.Add(2) //as there are 2 go routines
	go foo()
	go bar()
	wg.Wait()
}

func foo() {
	for i := 0; i < 10; i++ {
		fmt.Println("Foo: ", i)
		//time.Sleep(time.Duration(200 * time.Millisecond)) //demo concurrency
	}
	defer wg.Done()
}

func bar() {
	for i := 0; i < 10; i++ {
		fmt.Println("Bar: ", i)
		//time.Sleep(time.Duration(200 * time.Millisecond))
	}
	defer wg.Done()
}
