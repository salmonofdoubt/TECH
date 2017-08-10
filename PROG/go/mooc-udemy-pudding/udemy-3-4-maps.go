/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
///// k,v storage > map /////////////
/////////////////////////////////////

// a map is a pointer to data

package main

import "fmt"

//		 			  			key  value
func printmap(m map[string]int) {
	fmt.Printf("%T\n", m)
	fmt.Println("\n\n", m, "len", len(m))
}

func printval(v int) {
	fmt.Printf("%T\n", v)
	fmt.Println("\n\n", v)
}

func main() {
	//................k....v
	m1 := make(map[string]int) //make a map of string and int
	m1["k1"] = 7               //initialize map
	m1["k2"] = 19
	printmap(m1)

	v1 := m1["k1"]
	printval(v1)
	v1 = 8
	printval(v1)

	delete(m1, "k1") //delete key deletes the record
	m1["k3"] = 73
	printmap(m1)
}
