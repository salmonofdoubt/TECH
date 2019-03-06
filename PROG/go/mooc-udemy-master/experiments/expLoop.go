package main

import (
	"fmt"
)

func main() {
	//SIMPLE LOOP
	i := 10
	for ; i > 0; i-- {
		fmt.Println("IF", i)
	}

	//FOREVER
	for {
		fmt.Println("forever")
		if i < 2 {
			fmt.Println("i < 2")
			break
		}
	}

	//WHILE
	//  while n is positiv. So difference between for and while really is where
	//  the counter goes.

	n := 10
	for n > 0 {
		n--
		fmt.Println("WHILE:", n)
	}
}
