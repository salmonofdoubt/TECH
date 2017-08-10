package main

import "fmt"

func main() {
	inc := incrementer()                    // first example of using a closure, simple type inference
	fmt.Println(inc(), inc(), inc(), inc()) // then function calls
}

func incrementer() func() int { // outer func, returns a func
	i := 0              // i in outer function
	return func() int { // and this inner func, the Closure. It has access to outer i
		i++ // inner func then just increments by 1
		return i
	}
}
