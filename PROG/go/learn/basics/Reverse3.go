// revVowelsInString //////////////////////////
///////////////////////////////////////////////
// always start with simplest case ////////////
// then next simple case, etc /////////////////
// Today: basic string reversal - of place ////
// Note: Strings are bytes ////////////////////
///////////////////////////////////////////////

package main

import "fmt"

func main() {
	var r []byte
	vow := "aeiouAEIOU"
	var vpos []int

	fmt.Println(" Enter String with vowels:")
	fmt.Scan(&r)
	fmt.Println("\n", r)

	// better to loop over string of vowels rather than testing each
	for i := range r {
		for j := range vow {
			if r[i] == vow[j] {
				vpos = append(vpos, i) // i is the place
			}
		}
		fmt.Println(vpos) // cool up to here :)
	}
	if len(vpos) >= 2 { //the simplest case (1 vowel) skip to 39:
		start := 0
		end := len(vpos) - 1
		for start < end {
			r[vpos[start]], r[vpos[end]] = r[vpos[end]], r[vpos[start]]
			start++
			end--
		}
	}
	fmt.Println(string(r))
}
