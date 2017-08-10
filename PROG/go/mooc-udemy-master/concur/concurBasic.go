package main

import (
	"fmt"
	"time"
)

/*
they both *start* at the same time.
Without spacing them thru some delay, either one will randomly go first
*/
func main() {
	word1 := "yes I will"
	word2 := "or maybe not"

	for i := 0; i < 10; i++ {
		fmt.Println(i)
		go func(s string) {
			//time.Sleep(time.Second)
			fmt.Println(s)
		}(word1)

		go func(s string) {
			//time.Sleep(2 * time.Second)
			fmt.Println(s)
		}(word2)

		time.Sleep(3 * time.Second)
	}
}
