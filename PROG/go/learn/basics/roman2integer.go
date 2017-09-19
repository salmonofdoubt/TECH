/*
any of the letters representing numbers in the Roman numerical system:
I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1,000.
Letter placed after another of greater value adds (thus XVI or xvi is 16),
whereas letter placed before another of greater value subtracts (thus XC is 90).
*/
package main

import "fmt"

func main() {

	var input string
	var arabic int

	ms := map[string]int{
		"M": 1000,
		"D": 500,
		"C": 100,
		"L": 50,
		"X": 10,
		"V": 5,
		"I": 1,
	}

	fmt.Println("Enter Roman number:")
	fmt.Scan(&input)
	fmt.Println("Input was :", input)
	fmt.Println("ms: ", ms)

	/*
		Letter after greater value adds (thus XVI or xvi is 16),
		Letter before greater value subtracts (thus XC is 90).
	*/

	for i := range ms { // i is key, ms[i] is value.
		for j := range input {
			if i == string(input[j]) {
				arabic = arabic + ms[i]
			}
		}
	}
	fmt.Println("arabic:", arabic)
}
