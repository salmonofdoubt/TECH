package main

import (
	"fmt"
)

func main() {

	x := 5

	//fn being var of type func()
	fn := func() {
		fmt.Println("x is:", x)
	}

	fn()

	x++

	fn()
}
