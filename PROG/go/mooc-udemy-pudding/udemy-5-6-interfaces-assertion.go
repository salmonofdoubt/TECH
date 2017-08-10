///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
/////// interface Assertion ///////////
///////////////////////////////////////

/// for types int float32 float64 etc, there are type conversions
/// for types interface, there are type assertions

package main

import (
	"fmt"
)

func main() {
	//// type conversions
	var x int
	x = 3
	y := 7.14
	//conversion on the LEFT side
	//also this is widening the type (longer)
	fmt.Println("x+y: ", float64(x)+y)

	//// type interface assertions
	var name interface{} = "one"
	str, ok := name.(string) //assertion
	if ok {
		fmt.Printf("%T\n", str)
	} else {
		fmt.Println("value not a string")
	}

	var val interface{} = 7
	v, ok := val.(int)
	if ok {
		fmt.Printf("%T\n", v)
	} else {
		fmt.Println("value not an integer")
	}
	//assertion on the RIGHT side
	fmt.Println("yet conversion is needed: ", val.(int)+6)

}
