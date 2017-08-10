package main

import "fmt"

func main() {

	//////////////////////////////////////////////////////////
	//// create 2D array - short story ///////////////////////
	//////////////////////////////////////////////////////////
	aa := make([][]int, 4)
	for i := range aa {
		aa[i] = make([]int, 4)
		fmt.Println("\n", aa)
	}

	//////////////////////////////////////////////////////////
	//// create 2D array - long story ////////////////////////
	//////////////////////////////////////////////////////////

	// 1. compose x arrays in an array
	//    has 4 positions, they are empty [[] [] [] []]
	bb := make([][]int, 4)
	fmt.Println("\n\n", bb)

	for i := range bb {
		fmt.Printf("%T\n", bb[i])
		if bb[i] == nil {
			fmt.Println("oh man I'm nil, void, niente")
		}
	}

	// 2. for all arrays, make each element an array-int-type
	//    hence not nil, but initialised to 0
	for i := range bb {
		bb[i] = make([]int, 4)
		fmt.Println("\n", bb)
	}

	// 3. The test
	var row, col, val int
	fmt.Print("select coordinates x y (0..3): ")
	fmt.Scan(&row, &col) // assign
	fmt.Print("set value at this coordinate: ")
	fmt.Scan(&val)

	bb[row-1][col-1] = val
	fmt.Println(val)

	fmt.Printf("Pos [%d][%d] = %d\n", row, col, val)
	fmt.Println(bb)
}
