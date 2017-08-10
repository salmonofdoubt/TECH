package main

import "fmt"

func main() {
	s1 := []int{2, 4, 6}    //declared and initialized with values, malloc'ed
	s2 := []int{}           //declared and initialized without values, but malloc'ed
	var s3 []int            //declared and not initialised, not malloc'ed ***preferred***
	s4 := make([]int, 3, 5) //declared and initialized without values but len and cap

	fmt.Println(s1, s2, s3, s4)

	//this works, but it's silly
	var sillySlices []int
	sillySlices = append(sillySlices, s1...)
	sillySlices = append(sillySlices, s2...)
	sillySlices = append(sillySlices, s3...)
	sillySlices = append(sillySlices, s4...)
	fmt.Println("sillySlices:", sillySlices)

	//put these slices in another sclice
	slices := [][]int{
		s1,
		s2,
		s3,
		s4,
	}
	fmt.Println("slices:", slices)

	var betterSlices [][]int
	betterSlices = append(betterSlices, slices...)
	fmt.Println("betterSlices:", betterSlices)

	//underlying slice can be changed
	w1 := []int{1, 2, 3, 4, 5, 6}
	fmt.Println(w1)
	w2 := w1[2:4]
	fmt.Println(w2)
	w2[0] = 10
	fmt.Println(w2)
	fmt.Println(w1)

	// delete
	// on [1,3] append this [5,6]
	w1 = append(w1[:2], w1[4:]...)
	fmt.Println(w1)
}
