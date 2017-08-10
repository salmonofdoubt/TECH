package main

import "fmt"

func main() {

	greeter(3) // second example for using a closure
}

func greeter(number int) { // outer func, returns nothing
	i := 2 + number // i in outer function
	fn := func() {  // fn inner function, has access to text variable, that's a closure
		fmt.Println(i) // closures have access to variables even after exiting this block
	}
	fn() // and calling the closure
}
