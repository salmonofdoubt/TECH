package main

import "fmt"

func main() {
	printType("Text")
	printType(3)
	printType(4.01)

}

func printType(i interface{}) {
	switch i := i.(type) {
	case string:
		fmt.Println("string", i)
	case int:
		fmt.Println("int", i)
	case float64: //default float in go is float64
		fmt.Println("float64", i)

	}
}
