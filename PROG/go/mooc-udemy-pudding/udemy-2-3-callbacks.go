/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////// func callbacks /////////////
/////////////////////////////////////

///// pass by value (func), tightens the scope /////

package main

import "fmt"

func filter(nums []int, callback func(int) bool) []int {
	// take int slice, take int func which returns boolean. Return an int slice.
	xs := []int{}
	//var xs []int
	for _, v := range nums {
		if callback(v) { // if callback with v is true..
			xs = append(xs, v) // xs was empty slice, now appended by v
			//fmt.Println(xs)
		}
	}
	return xs
}

func main() {
	x := filter([]int{1, 2, 3, 4}, func(n int) bool {
		return n <= 3
	})
	// x := filter([]int{1, 2, 3, 4}, func(n int) bool { return n > 1 })
	// x is defined to be a function call
	// call filter with int array, an int func which executes {} and return a boolean

	fmt.Println(x)
}
