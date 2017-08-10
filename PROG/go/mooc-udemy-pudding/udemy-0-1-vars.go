/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func printinfo(input ...interface{}) {
	for _, v := range input {
		fmt.Printf("Value : %v \n", v)
		fmt.Printf("Type  : %T \n", v)
	}
	fmt.Println("---")
}
func main() {
	int1 := 1
	int2 := 2
	var int3 int
	printinfo(int1, int2, int3)

	xs1 := []int{4, 5, 6}
	var xs2 []int
	printinfo(xs1, xs2)

	str1 := "Andy"
	str2 := "Bowman"
	var str3 string
	printinfo(str1, str2, str3)

	var flt1 float32 = 2.81
	flt2 := 3.15 //interestingly that's a float64
	var flt3 float32
	printinfo(flt1, flt2, flt3)

	var bool1 bool
	bool2 := false
	var bool3 bool
	printinfo(bool1, bool2, bool3)
}
