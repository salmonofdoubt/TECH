package main

import (
	"fmt"
	"sync"
)

type safeCounter struct {
	i          int
	sync.Mutex //embedding, this type implements the Locker interface
}

func main() {

	sc := new(safeCounter) //creates just new object

	//run two different routines several times
	for i := 0; i < 100; i++ {
		go sc.Increment()
		go sc.Decrement()
	}

	fmt.Println(sc.GetValue())
}

func (sc *safeCounter) Increment() {
	sc.Lock() //the Lock() func is from sync.Mutex, which our type has access to
	sc.i++
	sc.Unlock()
}

func (sc *safeCounter) Decrement() {
	sc.Lock()
	sc.i--
	sc.Unlock()
}

func (sc *safeCounter) GetValue() int {
	// go run --race <this file>
	// w/out lock mechanism this code yields race conditions
	// because GetValue coud get called when i is still in/decrementing.
	sc.Lock() //so let's lock the value assignment
	v := sc.i
	sc.Unlock()
	return v
}

/*
$ go run -race mooc-udemy-master/concur/1_mutexMutex.go
==================
WARNING: DATA RACE
Read at 0x00c420010270 by main goroutine:
  main.main()
      /Users/abaumann/work/g3_golang/mooc-udemy-master/concur/1_mutexMutex.go:23 +0xb9

Previous write at 0x00c420010270 by goroutine 7:
  main.(*safeCounter).Increment()
      /Users/abaumann/work/g3_golang/mooc-udemy-master/concur/1_mutexMutex.go:28 +0x71

Goroutine 7 (finished) created at:
  main.main()
      /Users/abaumann/work/g3_golang/mooc-udemy-master/concur/1_mutexMutex.go:19 +0x72
==================
0
Found 1 data race(s)
exit status 66
*/
