package main

import "fmt"

func main() {

	i := 10
	for ; i > 0; i-- {
		defer fmt.Println("IF", i) // multiple defers results in LI-FO
	}

	n := 1
	for n <= 50 { //while n is up to 50, So difference between for and while really is where the counter goes.
		n += n
		defer fmt.Println("WHILE:", n)
	}

	//for { // an infinite loop
	//}
}
