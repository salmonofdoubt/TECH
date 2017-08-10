// demonstates a threadsafe map
// note we use pointers so to work on the same object, not on new objects
package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type MapCounter struct {
	m            map[int]int
	sync.RWMutex //embedding this type means its methods are available (here: Lock, RLock)
}

func main() {
	mc := MapCounter{m: make(map[int]int)} // create an object
	go runWriters(&mc, 10)                 // retain the original object, not copy every time
	go runReaders(&mc, 10)
	go runReaders(&mc, 10)
	time.Sleep(15 * time.Second)
}

func runWriters(mc *MapCounter, n int) { // Lock method needs to be used when doing writes
	for i := 0; i <= n; i++ {
		//mc.Lock()
		mc.m[i] = i * 10
		//mc.Unlock()
		time.Sleep(1 * time.Second)
	}
}

func runReaders(mc *MapCounter, n int) { // RLock method needs to be used when doing reads
	for { // endless for loop
		mc.RLock()
		v := mc.m[rand.Intn(n)] // asking for values 0 .. n-1
		mc.RUnlock()
		fmt.Println(v)
		time.Sleep(1 * time.Second)
	}
}

// RWMutex is more efficient when dealing with lots of read / writes
// Excellent for maps because maps read writes are not threadsafe.
