package main

import (
	"fmt"
	"os"
)

func echoargs1() {
	s, space := " ", " "
	for i := 1; i < len(os.Args); i++ {
		s += space + os.Args[i]
	}
	fmt.Println(s)
}

func echoargs2() {
	s, space := " ", " "
	for _, arg := range os.Args[1:] {
		s = s + space + arg
	}
	fmt.Println(s)
}

func main() {
	echoargs1()
	echoargs2()
}
