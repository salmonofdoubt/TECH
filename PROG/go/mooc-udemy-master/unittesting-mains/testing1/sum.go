package main

import "fmt"

func Sum(x int, y int) int {
	fmt.Println(x + y)
	return x + y
}

func main() {
	Sum(5, 5)
}
