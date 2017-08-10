///////////////////////////////////////////
//// The proof is in the pudding //////////
///////////////////////////////////////////
//// Error handling & multiple returns ////
//// No try /catch ////////////////////////
//// golint to exlude silly mistakes //////

package main

import (
	"fmt"
)

func main() {
	fmt.Println(safeDiv(4, 0))
	fmt.Println(safeDiv(4, 2))

	demPanic()
}

func safeDiv(n1, n2 int) int {

	defer func() { //executed even if a fatal error occurs
		fmt.Println(recover())
	}()

	solution := n1 / n2
	return solution
}

func demPanic() {

	defer func() { //executed even if a fatal error occurs
		fmt.Println(recover())
	}()

	panic("PANIC")
}
