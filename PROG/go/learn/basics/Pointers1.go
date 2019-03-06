package main

import "fmt"

func incNoPointer(arg int) {
	arg++
	fmt.Println("arg=", arg)
}

func incPointer(arg *int) {
	*arg++
	fmt.Println("*arg=", *arg)
}

func main() {
	i := 10
	fmt.Println("1:", i)

	incNoPointer(i)
	fmt.Println("2:", i)

	incPointer(&i)
	fmt.Println("3:", i)
}
