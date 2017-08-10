////////////////////////////////////
//// The proof is in the pudding ///
///////// recursion ////////////////

//always start with if, one where the fucn calls itself, one where it doesn't
//handle simples case (no recursion)

package main

import "fmt"

func fact(x int) int {
	if x == 0 { //the simplest possible calculation
		fmt.Println("1st return:", x, "return 1")
		return 1
	}
	aux := fact(x - 1) //next simplest possible calculation
	return x * aux
}

func main() {
	fmt.Println("Start")
	fmt.Println(fact(6))
}
