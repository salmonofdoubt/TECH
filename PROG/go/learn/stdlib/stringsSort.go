package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {

	sampString := "Hello World"
	fmt.Println(strings.Contains(sampString, "lo"))
	fmt.Println(strings.Count(sampString, "l"))
	fmt.Println(strings.Index(sampString, "lo"))
	fmt.Println(strings.Replace(sampString, "l", "x", 1))

	csvString := "1,2,3,4,5,6,7,8,9"
	csvStringSplit := strings.Split(csvString, ",")
	fmt.Printf("%T %v", csvStringSplit, csvStringSplit)

	letters := []string{"b", "c", "a"}
	sort.Strings(letters)
	fmt.Println("\nletters:", letters)

	numString := []string{"3", "2", "3"}
	fmt.Println("\nnumString:", numString)

	numStringJoined := strings.Join(numString, ",")
	fmt.Printf("%T %v", numStringJoined, numStringJoined)

}
