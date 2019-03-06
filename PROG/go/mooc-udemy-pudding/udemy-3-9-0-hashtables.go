/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//// Hash Table Step by Step ////////
/////////////////////////////////////

package main

import (
	//	"bufio"
	"fmt"
	//	"log"
	//	"net/http"
)

func print(a ...rune) { // this will always use slice notation []
	fmt.Printf("%T %v %c\n", a, a, a)

}

func main() {
	l1 := 'A' // letter '' vs string ""
	//UTF8 is 1..4 B coding scheme (int32). Prints Type, UTF8value, char.

	l2 := rune("ABCD"[3])
	// take a rune from a string

	l3 := l2 + 2

	l4 := rune(l3)

	l5 := rune(66)

	print(l1, l2, l3, l4, l5)

	//var l string
	for i := 0; i < 4; i++ {
		fmt.Println(i)
		fmt.Println(string(i + 100))
	}
}
