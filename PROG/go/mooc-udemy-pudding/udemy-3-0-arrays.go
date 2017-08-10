/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////// arrays (static) //////////////
/////////////////////////////////////

// slice, array: lists
// map         : k,v storage
// channel     : ...
// those 3 are ref types, can use "make", hence dims need to be right

// struct      : data structure

package main

import (
	"crypto/rand"
	"fmt"
	"io"
)

func main() {

	///// var //////////////////////////////////////////////////////////////////
	var z [5]int
	fmt.Println("\nArray z: ", len(z), cap(z), z) // [0 0 0 0 0]

	for i := 0; i < 5; i++ {
		z[i] = i
	}
	fmt.Println("\nArray z: ", len(z), cap(z), z) // [0 1 2 3 4]

	for i, v := range z {
		fmt.Printf("Array z: %v - %T \n", v, v)
		if i == 2 {
			break
		}
	}

	///// shorthand ///////////////////////////////////////////////////////////
	row := [5]int{} // row, col := [5]int{} - doesnt work
	col := [5]int{}

	for i := range row {
		row[i] = i
		fmt.Println("row: ", len(row), cap(row), row, i)
		for j := 0; j < 5; j++ {
			col[j] = j
			fmt.Println("col: ", len(col), cap(col), col, j+100)
		}
	}

	/*
		Stupidly, arrays in go are always 1D, so above creates just tow 1D arrays.
		In fact it repopulates col 5x :(
		So what needs to be done is making a new array in each step i.
		See file ...arrays2
	*/

	///// make /////////////////////////////////////////////////////////////////
	combo := make([]int, 10)
	combo = append(row[:], col[:]...)
	fmt.Println("\n combo: ", len(combo), cap(combo), combo)

	////////////////////////////////////////////////////////////////////////////
	var nonce [2]byte
	fmt.Println("\nnonce     : ", nonce)
	io.ReadFull(rand.Reader, nonce[:]) //expects slice, slice everything [:]
	fmt.Println("nonce rand: ", nonce)

}
