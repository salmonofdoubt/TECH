/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func buzzfizz() {
	for i := 1; i <= 100; i++ {
		if i%3 == 0 && i%5 == 0 { //the simplest, catching the most cases
			fmt.Println(i, " -- FizzBuzz")
		} else if i%3 == 0 {
			fmt.Println(i, " -- Fizz")
		} else if i%5 == 0 {
			fmt.Println(i, " -- Buzz")
		} else {
			fmt.Println(i)
		}
	}
}

func sum() {
	sum := 0
	for i := 0; i < 10; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum = sum + i //i<10 >> 23
		}
	}
	fmt.Println(sum)
}

func main() {
	buzzfizz()
	sum()
}
