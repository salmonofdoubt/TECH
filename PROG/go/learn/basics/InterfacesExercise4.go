package main

//SMIFO
//S Create Structs with relevant fields (a concrete type has methods attached).
//M Create Methods with struct as Receiver. Method names will always be identical.
//I Create Interface associated with Methods M, using Method signatures as field.
//F Create Function that takes the Interface I, returns I.M()
//O Create Objects, use them on the Function F

// So here is an example how an interface does different things based on types.
// It also demonstrates using composite types :)

import "fmt"

//Person ...
type Person struct {
	name        string
	age         int
	city, phone string
}

//Group ...
type Group struct {
	person  Person
	groupID int
}

func (p Person) startConv() string {
	return fmt.Sprintf("startConv method %v:", p.name)
}

func (g Group) startConv() string {
	return fmt.Sprintf("startConv Group %v, %v:", g.groupID, g.person.name)
}

//People ...
type People interface { // implements Person objects
	startConv() string
	//getDetails() string
}

//Greeter ...
func Greeter(p People) string {
	return fmt.Sprintf("Greeter func %v:", p.startConv())
	//return fmt.Sprintf("Greeter func %v:", p.getDetails())
}

func main() {
	g := Group{
		groupID: 2,
		person: Person{
			name:  "Berni",
			age:   30,
			city:  "Moscow",
			phone: "091 11 223 22",
		},
	}

	p := Person{
		name:  "Joe",
		age:   42,
		city:  "Boston",
		phone: "001 89 252 66",
	}
	fmt.Println(Greeter(g))
	fmt.Println(Greeter(p))
}

//smifo
