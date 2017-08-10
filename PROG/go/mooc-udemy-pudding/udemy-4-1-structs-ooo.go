/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////////// Structs ////////////////
///////////// OOO ///////////////////

package main

import "fmt"

type person struct { //person is a type, or a class struct with these fields:
	first string
	last  string
	age   int
}

func main() {
	p1 := person{"James", "Connolly", 174} //var of type struct {with struct literals}
	p2 := person{"Marie", "Courie", 210}

	p1.fullName()
	p2.fullName()
}

//the func that is receiving a struct is a method
//takes p of type 'person', called fullName, no return
func (p person) fullName() {
	fmt.Println(p.first, p.last, p.age)
}
