// author: abaumann@google.com
// Basic Slice operations implementation

package main

import (
	"fmt"
	"reflect"
)

// func append(slice []Type, elems ...Type) []Type
func pushExample(x, y []string) {
	fmt.Println("\n", "[pushExample]                        x,y:", x, y)

	x = append(x, y...)

	fmt.Println("x = append(x, y...)                      :", x)
}

func popExample(x []string) {
	fmt.Println("\n", "[popExampleSlice]                       :", x)

	x = x[:len(x)-1]

	fmt.Println("x = x[:len(x)-1]                         :", x)
}

// func copy(dst, src []Type) int // Dest must have same lenght as source
func copyExample(x, y []string) {
	fmt.Println("\n", "[copyExample]                         x,y:", x, y)

	copy(y, x)

	fmt.Println("copy(y, x)                             x,y:", x, y)
}

func cutExample(x []string, i, j int) {
	fmt.Println("\n", "[cutExample]                      x, i, j:", x, i, j)

	x = append(x[:i], x[j:]...)

	fmt.Println("x = append(x[:i], x[j:]...)               :", x)
}

func deleteExample(x []string, i int) {
	fmt.Println("\n", "[deleteExample]                      x, i:", x, i)

	x = append(x[:i], x[i+1:]...)

	fmt.Println("x = append(x[:i], x[i+1:]...)             :", x)
}

func insertExample(x, y []string, i int) {
	fmt.Println("\n", "[insertExample]                   x, y, i:", x, y, i)

	x = append(x[:i], append(y, x[i:]...)...)

	fmt.Println("x = append(x[:i], append(y, x[i:]...)...) :", x)
}

func shiftExample(x []string) {
	fmt.Println("\n", "[shiftExample]                          x:", x)
	right := x[1:]
	fmt.Println("right := x[1:]                            :", right)
	left := x[0 : len(x)-1]
	fmt.Println("left := x[0:len(x)-1]                     :", left)
}

func reverseExample(x []string) {
	fmt.Println("\n", "[reverseExample]                        x:", x)
	for i := len(x)/2 - 1; i >= 0; i-- {
		opp := len(x) - 1 - i
		x[i], x[opp] = x[opp], x[i]
	}
	fmt.Println("x[i], x[opp] = x[opp], x[i]               :", x)
}

///////////////////////////////////////////////////////////////////////////////

func main() {

	//a few vars that will be used
	a1 := []string{"1", "2", "3", "4"}
	a2 := []string{"5", "6", "7", "8", "9", "10"}

	b1 := []string{"copy this"}
	b2 := make([]string, len(b1))

	i, j := 1, 3

	//s := "string"

	//func var to quickly check source vars
	check := func() {
		a1reset := []string{"1", "2", "3", "4"}
		a2reset := []string{"5", "6", "7", "8", "9", "10"}
		if reflect.DeepEqual(a1, a1reset) != true {
			fmt.Println(a1, a2, "/////////////////// a1 changed, resetting")
			a1 = a1reset
			fmt.Println(a1, a2)

		} else if reflect.DeepEqual(a2, a2reset) != true {
			fmt.Println(a1, a2, "/////////////////// a2 changed, resetting")
			a2 = a2reset
			fmt.Println(a1, a2)
		} else {
			fmt.Println(a1, a2)
		}
	}

	check()

	pushExample(a1, a2)
	check()

	popExample(a1)
	check()

	copyExample(b1, b2)
	check() //b2 actually changed permanently

	cutExample(a2, i, j)
	check() //a2 actually changed

	deleteExample(a1, i)
	check() //a1 actually changed

	insertExample(a1, b1, i)
	check()

	shiftExample(a2)
	check()

	reverseExample(a2)
	check() //a2 actually changed
}
