package main

import "fmt"

func main() {
	for i := 0; i <= 2; i++ {
		switch i {
		case 0:
			fmt.Println(i, "0")
		case 1:
			fmt.Println(i, "1")
		default:
			fmt.Println(i, "but there is no case 2, so default")
		}
	}
}
