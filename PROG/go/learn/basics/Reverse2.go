// Exercise reverse ints in a string //////////
// https://blog.golang.org/strings:  //////////
///////////////////////////////////////////////
// string are not chars, they are bytes ///////
// string abc is immutable (not changing) /////
// array of string [a,b,c] can be swapped /////
///////////////////////////////////////////////
// Copycat: See how it works? /////////////////
///////////////////////////////////////////////
// this is basic in place swap operation //////
///////////////////////////////////////////////

package main

import "fmt"

func reverseIntsInString(s string) string {

	r := []byte(s) //convert string to bytes ASCII
	fmt.Println(r)

	var pos []int //array with vowel positions

	//si is int
	//sv is int32
	//these integers are strings
	for si, sv := range s { //loop over string and just find integer *positions*
		if sv == '0' || sv == '1' || sv == '2' || sv == '3' || sv == '4' ||
			sv == '5' || sv == '6' || sv == '7' || sv == '8' || sv == '9' {
			pos = append(pos, si) //creates an array of integer positions
		}
		//s[0] is unit8 (rune)
		fmt.Printf("%T%T\n", s[0], s[1])
	}
	fmt.Println("int positions:", pos)

	if len(pos) >= 2 { //at least two ints positions
		start := 0          // we look at ...
		end := len(pos) - 1 // ... both sides to swap
		for start < end {
			r[pos[start]], r[pos[end]] = r[pos[end]], r[pos[start]]
			start++
			end--
		}
	}
	return string(r)
}

func main() {

	var str string
	fmt.Println("Enter a string: ")
	fmt.Scan(&str)
	fmt.Println(reverseIntsInString(str))
}
