/*
Data Race
go run -race file.go
WARNING: DATA RACE
*/
package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	start1 := time.Now()
	raceOne()
	end1 := (time.Since(start1))

	start2 := time.Now()
	raceOneFixed()
	end2 := (time.Since(start2))

	start3 := time.Now()
	raceTwo()
	end3 := (time.Since(start3))

	start4 := time.Now()
	raceTwoFixed()
	end4 := (time.Since(start4))

	end := []time.Duration{end1, end2, end3, end4}
	fmt.Println(end)
}

func raceOne() {
	var wg sync.WaitGroup
	wg.Add(5)
	for i := 0; i < 5; i++ {
		go func() {
			fmt.Println("raceOne():", i, "Not the 'i' you are looking for.")
			wg.Done()
		}()
	}
	wg.Wait()
}

/*
var i in function literal is the same as used by the loop, so the read in
goroutine races with the loop increment (prints 55555, not 01234)
This can be fixed by making a copy of the variable:
*/
func raceOneFixed() {
	var wg sync.WaitGroup
	wg.Add(5)
	for i := 0; i < 5; i++ {
		go func(j int) { //
			fmt.Println("raceOneFixed():", j, "j")
			wg.Done()
		}(i) //call the routine with "i"
	}
	wg.Wait()
}

func raceTwo() {
	c := make(chan bool)
	m := make(map[string]string)
	go func() {
		m["1"] = "a" // First conflicting access.
		c <- true
	}()
	m["2"] = "b" // Second conflicting access.
	<-c
	for k, v := range m {
		fmt.Println(k, v)
	}
}

func raceTwoFixed() {
	c := make(chan bool)
	m := make(map[string]string)
	go func(v string) {
		m[v] = "a" // First conflicting access.
		c <- true
	}("1")
	go func(v string) {
		m["2"] = "b" // Second conflicting access.
		<-c
	}("2")
	for k, v := range m {
		fmt.Println("hola?", k, v)
	}
}
