/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////////// Structs ////////////////
///////////// OOO ///////////////////

package main

import "fmt"

//first, explain self declared types (classes)
type foo float64 //my type "foo", underlying type float64

func main() {
	var v1 foo
	var v2 int
	fmt.Printf("%T %v \n", v1, v1)
	fmt.Printf("%T %v \n", v2, v2)
	fmt.Println(int(v1) + v2) //otherwise type converstion error
}
