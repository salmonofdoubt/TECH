/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func buzzfizz() {
	for i := 1; i <= 100; i++ {
		if i%3 == 0 && i%5 == 0 {
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
	fmt.Printf("%T \n", sum)
	for i := 0; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum = sum + i
		}
	}
	fmt.Println(sum)
}

func main() {
	buzzfizz()
	sum()
}
