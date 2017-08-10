package main

import "fmt"

func main() {

	text := "Hello you anonymous function!"

	func(message string) { // anonymous function declared
		fmt.Println(message)
	}(text) // anonymous function called
}
