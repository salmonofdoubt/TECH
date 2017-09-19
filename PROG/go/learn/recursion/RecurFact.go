////////////////////////////////////
//// The proof is in the pudding ///
////////////////////////////////////

//always start with if, one where the fucn calls itself, one where it doesn't
//handle simples case (no recursion)

package main

import "fmt"

func fact(x int) int {
	if x == 0 { //the simplest possible scenario top
		//fmt.Println(x, "return 1")
		return 1
	}
	//fmt.Println(x, "* fact(", x-1, ")")
	return x * fact(x-1)
}

func main() {
	var n int
	fmt.Println("Integer: ")
	fmt.Scan(&n)

	fmt.Println(fact(n))
}
