package main

import "fmt"

type set map[string]struct{} // a string map

func main() {
	s := make(set)
	s["item1"] = struct{}{} // value is an empty struct with empty values. Hilarious.
	s["item2"] = struct{}{}

	fmt.Println(getSetValues(s))

}

func getSetValues(s set) []string {
	var retValue []string
	for key := range s {
		retValue = append(retValue, key)
	}
	return retValue
}
