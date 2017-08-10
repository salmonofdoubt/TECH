package main

import "fmt"

func wrapper() func() int {
	var x int
	return func() int {
		x++
		return x
	}
}

func main() {
	incrementA := wrapper()
	incrementB := wrapper()
	fmt.Println("A:", incrementA())
	fmt.Println("A:", incrementA())
	fmt.Println("B:", incrementB())
	fmt.Println("B:", incrementB())
	fmt.Println("B:", incrementB())
}

/*
closure helps us limit the scope of variables used by multiple functions
without closure, for two or more funcs to have access to the same variable,
that variable would need to be package scope
*/

/*
All material is licensed under the Apache License Version 2.0, January 2004
http://www.apache.org/licenses/LICENSE-2.0
*/
