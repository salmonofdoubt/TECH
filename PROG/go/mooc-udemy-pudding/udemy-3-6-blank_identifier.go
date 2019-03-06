/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
///// use blank identifiers /////////
/////////////////////////////////////
//// changed ////////////////////////

package main

import "fmt"

func two() (int, bool) {
	return 42, 1 == 1
}

func main() {
	r, ok := two()
	fmt.Println(r, ok)

	s, _ := two()
	fmt.Println(s)

	_, t := two()
	fmt.Println(t)
}
