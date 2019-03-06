package main

import "fmt"

func main() {
	for row := 1; row <= 3; row++ {
		for col := 1; col <= 4; col++ {
			fmt.Printf("%d", col)
		}
		fmt.Printf("\n")
	}
}
