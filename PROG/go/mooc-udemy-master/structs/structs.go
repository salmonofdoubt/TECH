// Comment main ...
package main

import (
	"fmt"
	"reflect"
)

// CMember struct outside of main(), the template...
type CMember struct {
	name      string
	age       int
	address   string
	rank      string
	clearance int
}

// PrintRank a method of struct CMember
func (cm CMember) PrintRank() {
	fmt.Println(cm.rank)
}

func main() {

	//struct literal
	cm1 := CMember{"Kevin1", 51, "Station Mars1", "Sergant1", 1}

	//or
	cm2 := CMember{
		name:      "Kevin2",
		age:       52,
		address:   "Station Mars2",
		rank:      "Sergant2",
		clearance: 2,
	}

	//struct var
	var cm3 CMember
	cm3.name = "Kevin3"
	cm3.age = 53
	cm3.address = "Station Mars3"
	cm3.rank = "Sergant3"
	cm3.clearance = 3

	fmt.Println(cm1, cm2, cm3)

	// create an array of structs
	var crew []CMember
	crew = append(crew, cm1, cm2, cm3, CMember{"Jo", 12, "Kids place", "Station Mars1", 0})

	for _, v := range crew {
		fmt.Println(v)
	}

	// structs as value in a map

	//var m map[string]CMember
	//or
	m := make(map[string]CMember)

	// test for key. If non-existing, value (here a struct) is added with this key
	m["string1"] = cm1
	m["string2"] = CMember{"Jo", 12, "Kids place", "Station Mars1", 0}

	// in a range assignment, second var (value), should be omitted
	for k := range m {
		fmt.Println("k:", k)
	}
	for _, v := range m {
		fmt.Println("v:", v)
	}
	for k, v := range m {
		fmt.Println("k,v:", k, v)
	}

	//two-value assigment
	v, ok := m["string2"]          //v becomes value stored under key "string1"
	fmt.Println("key ok?:", v, ok) //ok is a boolean

	delete(m, "string2") // func delete(m map[Type]Type1, key Type)
	for k, v := range m {
		fmt.Println("after deleting key 'string2':", k, v)
	}

	m["string2"] = cm2
	m["string3"] = cm3

	// finally why not testing the method we wrote
	for _, v := range m {
		reflect.ValueOf(v).MethodByName("PrintRank").Call([]reflect.Value{})
	}
}
