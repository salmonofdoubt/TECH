/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
package main

import "fmt"

func main() {
	//anonymous function, a func expression.
	greeting := func() {
		fmt.Println("Ho")
	}
	greeting() //greeting being a function

	go func(msg string) {
		fmt.Println(msg)
	}("going") //pass this to the function, becomes msg

	go func() {
		fmt.Println("Hi")
	}() //here there is nothing to pass to the function
}
