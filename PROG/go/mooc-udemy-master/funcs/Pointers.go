package main

/*
*** func pass by value, so use pointers
passing by value
a) can be expensive
b) wont change the original value
*/

import "fmt"

func main() {
	x := 5
	changeX(x)
	fmt.Println("Value of X: ", x)
}

func changeX(x int) {
	x = 10
}
