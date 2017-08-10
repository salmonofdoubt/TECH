/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//////////// Structs ////////////////
/////// OOO - Inheritance////////////

package main

import "fmt"

//Person exported for no reason
type Person struct { //declare person to be a type (a class) struct
	First string //fields, composites
	Last  string
	Age   int
}

//func that receives, here a struct, is a method, here called fullName
//   (receiver) funcName() (several returns)
func (p Person) fullName() (string, string, int) { //
	return p.First, p.Last, p.Age
}

//DoubleZero exported for no reason
type DoubleZero struct {
	Person
	LicenseToKill bool
}

func (p DoubleZero) fullNameLic() (string, bool) {
	desc := "License to kill: "
	return desc, p.LicenseToKill
}

func main() {
	p1 := Person{"James", "Connolly", 174} //var of type person {with struct literals}
	p2 := Person{"Marie", "Courie", 210}

	p3 := DoubleZero{
		Person: Person{ //DoubleZero inherits everything from Person, plus a License
			First: "James",
			Last:  "Bond",
			Age:   30,
		}, //comma ends the initialization of Person
		LicenseToKill: true,
	} //   whereas this ends the variable p3.Person

	fmt.Println(p1.fullName())
	fmt.Println(p2.fullName())
	fmt.Println(p3.fullName())
	fmt.Println(p3.fullNameLic())
}
