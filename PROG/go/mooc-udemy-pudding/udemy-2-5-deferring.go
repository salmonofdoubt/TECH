/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////////// defer //////////////////
/////////////////////////////////////

package main

import "fmt"

func hello() {
	fmt.Println("Hello")
}

func world() {
	fmt.Println("World")
}

func main() {
	defer hello() //defers to main's exit, such as close a file
	world()
}
