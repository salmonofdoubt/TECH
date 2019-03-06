package main

import (
	"fmt"
	"os"
)

func main() {
	args()
	show()
}

func show() {
	var n = 100
	for i := 1; i <= n; i++ {
		x := false
		for d := 2; d <= i/2; d++ {
			if i%d == 0 {
				x = true
				break
			}
		}
		if x == false {
			fmt.Println("PRIME:", i)
		}
	}
}

func args() {
	s, space := " ", " "
	for _, arg := range os.Args[1:] {
		s = s + space + arg
	}
	fmt.Println(s)
}
