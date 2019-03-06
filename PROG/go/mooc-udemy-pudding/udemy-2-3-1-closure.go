/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////// scope closure/ /////////////
/////////////////////////////////////

package main

import "fmt"

func main() {
	num3 := 3

	doubleNum := func() int {
		num3 *= 2
		return num3
	}
	fmt.Println(doubleNum()) //6
	fmt.Println(doubleNum()) //12

	fmt.Println(doubleNumOutside(num3)) //24
	fmt.Println(doubleNumOutside(num3)) //24
}

func doubleNumOutside(n int) int {
	res := n * 2
	return res

}
