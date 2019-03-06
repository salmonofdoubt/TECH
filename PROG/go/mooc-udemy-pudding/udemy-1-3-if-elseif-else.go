/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func main() {

	b := false
	if food := "Chocolade"; b { // basically: is food initilzed?
		fmt.Println(food)
	}

	if false { //but it's true
		fmt.Println("first")
	} else if false {
		fmt.Println("second")
	} else {
		fmt.Println("third")
	}
}
