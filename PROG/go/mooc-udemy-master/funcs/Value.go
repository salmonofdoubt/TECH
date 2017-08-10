package main

// Functions are values

import "fmt"

func main() {

	add := func(a, b int) int {
		return a + b
	}
	fmt.Println(add(2, 4))           // 6, how boring
	fmt.Println(multiplyVal(2, add)) // awesomeness, see func signature
}

func multiplyVal(val int, fn func(a, b int) int) int {
	return val * fn(val, val) //8
	//      2  *    2  +  2
	//      2  *      4
}
