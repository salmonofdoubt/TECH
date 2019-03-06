/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
///// * k,v storage? > map! /////////
///// * map is a ref type ///////////
///// * uses make, hooray ///////////
///// * use blank identifiers ///////
/////////////////////////////////////

package main

import "fmt"

//                    k     v    r
func printmap(m map[string]int) int {
	//fmt.Printf("%T\n", m)
	fmt.Println("\n\n len", len(m))
	return 1
}

func printval(v int) {
	//fmt.Printf("%T\n", v)
	fmt.Println("\n\n", v)
}

func main() {

	///// make        k    v ///////////////////////////////////////////////////
	m1 := make(map[string]int) //makes empty k,v map
	fmt.Println("\n\nm1:", m1, "len", len(m1))
	m1["k1"] = 1 //initialises a map
	m1["k2"] = 2
	fmt.Println("\n\nm1:", m1, "len", len(m1))

	///// var m = , composite in {}, needs "=" /////////////////////////////////
	var m2 = map[string]int{
		"b": 100,
		"c": 300,
		"d": 100,
		"a": 200,
	}
	fmt.Println("\n\nm2:", m2, "len", len(m2))

	///// shorthand, composite in {} ///////////////////////////////////////////
	m3 := map[string]int{"k1": 10, "k2": 20} //declare and initilize k,v map
	fmt.Println("\n\nm3:", m3, "len", len(m3))

	///// I think "make" just becomes my ony friend
	m4 := make(map[string]string)
	m4["Name1"] = "Baumann" // oh, and keys must be unique
	m4["Name2"] = "Westerwelle"
	fmt.Println("\n\nm4:", m4, "len", len(m4))

	///// playground ///////////////////////////////////////////////////////////
	delete(m3, "k1") //deleting k1, deletes the record
	printmap(m3)
	m3["k3"] = 33
	printmap(m3)

	v := m3["k3"] //getting value
	printval(v)

	// maps can use blank identidfiers as they have two returns
	// like functions that have multiple returns if declared
	_, k := m3["k1"]
	fmt.Println("key present?", k) // k2 is 0, but is it really present

	/*
		//// key 2 is 0, but unclear if it is present
		key := m[2]
		fmt.Println("key present?", key)
		//// basically
		fmt.Println(m[2])

		//// hence
		v, k := m[2]
		fmt.Println("key present?", v, k) // v of k is 0, but is k really present
	*/
}
