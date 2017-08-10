// The proof is in the pudding
package main

import "fmt"

func main() {
	for i := 0; i < 100; i++ {
		var x = i % 2
		if x == 1 {
			fmt.Println(i, "odd")
		} else {
			fmt.Println(i, "even")
		}
	}
}
