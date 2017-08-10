/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////////// Structs ////////////////
///////////// OOO ///////////////////

package main

import "fmt"

type person struct { //declare person to be a type (a class) struct
	first string //fields, composites
	last  string
	age   int
}

func main() {
	p1 := person{"James", "Connolly", 174} //var of type person {with struct literals}
	p2 := person{"Marie", "Courie", 210}
	fmt.Println(p1.fullName())
	fmt.Println(p2.fullName())
}

//func receiving a struct, is a method, called fullName, returns a string
//    receiver  funcName para return
func (p person) fullName() string {
	return p.first + p.last
}
