package main

import "fmt"

func main() {
	arr := []int{}
	fmt.Println(arr)

	const (
		big   = 1 << 4
		small = big >> 2
	)

	fmt.Println(big, "\n", small)

	//enums are constants with similar behaviour

	/*
		Go Lang is  strictly typed
		Prevent many simple errors
		This means that the development is faster and the code is often more reliable.

		Knowing how to correctly use constants and enums is essential to make the code even more strict.
	*/

	type enum int

	const (
		MON enum = 1 + iota
		TUE
		WED
		THU
		FRI
		SAT
		SUN
	)
	fmt.Println(MON, SUN)

	const (
		STRICTLY_TYPED = 1
		LOOSELY_TYPED  = 2
	)

	type Language struct {
		name   string
		typing int
	}

	lang := Language{"Go", STRICTLY_TYPED}
	fmt.Print(lang)

}
