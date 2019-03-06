package main

import "fmt"

func main() {

	inc := incrementer() // not called, just type inference

	if i := inc(); i < 2 { // i is now 1, since inc() gets executed through it's () here, right
		fmt.Println("if:", i) // not true
	} else if i == 3 {
		fmt.Println("if i == 3:", i)
	} else { // not be tested anymore
		fmt.Println("if block: i > 1:", i)
	}
}

func incrementer() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}
