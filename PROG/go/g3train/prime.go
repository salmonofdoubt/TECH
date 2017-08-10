package main

import "fmt"

func prime(x int) {
	//for all numbers up to x
	for n := 1; n <= x; n++ {
		var x bool //false
		//we know 6/4 will not yield a rational number...
		for d := 2; d <= n/2; d++ {
			//if there is no remainder it's not prime, set x to 1 and break
			if (n % d) == 0 {
				x = true
				break
			}
		}
		if x == false {
			fmt.Println("*PRIME*", n)
		}
	}
}

func main() {
	prime(100)
}
