// Reverese string with and without spaces ///
// always start with simplest case ////////////
// Note: Strings are bytes ////////////////////

package main

import (
	"bufio"
	"fmt"
	"os"
)

func reverseString1(s string) string {
	var res string
	for _, v := range s { //omit key
		//fmt.Println(v)      //ASCI
		res = string(v) + res //l1 l2l1 l3l2l1 ..
	}
	//fmt.Println("final :", res)
	return res
}

func reverseString2(s string) string {
	bs := []byte(s)                    //convert string to bytes
	var out []byte                     //create new array of type bytes
	for i := len(s) - 1; i >= 0; i-- { //start with the last element in s
		out = append(out, bs[i])
		// fmt.Println(out)
	}
	return string(out) //return the string
}

func main() {
	var s string
	fmt.Println("String w/o spaces: ")
	fmt.Scan(&s)
	fmt.Println(reverseString1(s))
	fmt.Println(reverseString2(s))

	//read string line incl spaces
	reader := bufio.NewReader(os.Stdin) //creates a reader
	fmt.Println("String w/ spaces: ")
	str, _ := reader.ReadString('\n') //uses that reader
	fmt.Println(reverseString1(str))
	fmt.Println(reverseString2(str))
}
