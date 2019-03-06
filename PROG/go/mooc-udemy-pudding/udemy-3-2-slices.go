/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
/////////// slices //////////////////
/////////////////////////////////////

package main

import "fmt"

func printthis(s []int, ind int) {
	//fmt.Printf("%T\n", s)
	fmt.Println("s", ind, ":", s, "len: ", len(s), "cap: ", cap(s))
}

func main() {
	///// var //////////////////////////////////////////////////////////////////
	var s1 []int //slice, a dynamic array, can change in size
	printthis(s1, 1)
	s1 = []int{1, 3, 5, 6}
	printthis(s1, 10)

	///// shorthand ////////////////////////////////////////////////////////////
	s2 := []int{70, 90, 20, 10}
	printthis(s2, 2)

	///// make /////////////////////////////////////////////////////////////////
	s3 := make([]int, 2, 3) //len 2, cap 3, doubles cap automatically
	printthis(s3, 3)
	for i := 0; i < 4; i++ {
		s3 = append(s3, i)
		printthis(s3, 3)
	}

	s3 = append(s3, s2...)
	printthis(s3, 31)

	s3 = append(s3[:2], s3[7:]...) // Deleting is lame: len reduces, cap sticks
	printthis(s3, 32)
}
