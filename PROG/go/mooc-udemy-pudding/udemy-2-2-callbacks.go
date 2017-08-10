/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

//////// func callbacks /////////////

package main

import "fmt"

func visit(nums []int, callback func(int)) { //takes int slice, and int func
	fmt.Printf("%T\n%T\n", nums, callback)
	for _, v := range nums { // for range of nums, call back func, which was passed, and use the values there
		callback(v)
	}
}

func main() {
	visit([]int{1, 2, 3, 4}, func(n int) {
		fmt.Println(n)
	})

	/* probably better to understand when written this way:
	   visit           ([]int{1,2,3,4} , func(n int) {fmt.Println(n)})
	   call visit with (a slice of ints, a func that takes an int which does {this})
	*/

}
