package main

import "fmt"

func main() {
	foo()
	bar()
}

func foo() {
	for i := 0; i < 45; i++ {
		fmt.Println("Foo:", i)
	}
}

func bar() {
	for i := 0; i < 45; i++ {
		fmt.Println("Bar:", i)
	}
}

/*
All material is licensed under the Apache License Version 2.0, January 2004
http://www.apache.org/licenses/LICENSE-2.0
*/
