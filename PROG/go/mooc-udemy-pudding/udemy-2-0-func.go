/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func main() {
	fmt.Println(greet("A", "B"))
	fmt.Println(concat("D", "E", "F", "2", "Many!"))
	printinfo(3, "2", "woot")
}
func greet(name1, name2 string) (string, string) {
	//multiple returns in one return statement:
	str1 := "Mr. " + name1 + name2
	str2 := "Ms. " + name1 + name2
	return str1, str2
}

//variadic: takes any number of the type creating a sclice
//here: returns single string
func concat(item ...string) string {
	newStr := ""
	for _, v := range item {
		newStr += v
	}
	return newStr
}

//interface{} takes any type
func printinfo(input ...interface{}) {
	for _, v := range input {
		fmt.Printf("Type and Value : %T %v\n", v, v)
	}
}
