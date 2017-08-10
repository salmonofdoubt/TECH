package main

import "fmt"

func main() {

	printfunc := getMessage() // just ordinary type inference, var becoming a func
	printfunc("Test")         // execute the func, meaning execute getMessage()
}

func getMessage() func(string) { // returns an anonymous function
	return func(message string) { //which takes "message", and which we provided "Test"
		fmt.Println(message)
	}
}
