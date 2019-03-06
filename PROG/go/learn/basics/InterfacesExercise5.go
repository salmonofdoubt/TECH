// author: abaumann@google.com
// From go/gonotes Dec 13 2016, HWK 3

/*
User defined types, Interfaces (overview)

Create a type called MyList based on a slice of integers.
Implement the methods below:
Method to get the number of elements in MyList.
Method to append any number of elements at the end of MyList.
Method to insert any number of elements at a given position.
Method to modify the element at a given position.
Method to remove a given number of elements starting at given position.
Method to remove all elements in MyList.
*/

package main

import "fmt"

// MyList a type based on a slice of integers.
type MyList []int

// GetNumberElements ...
func (x MyList) GetNumberElements() int {
	var res int
	for i := range x {
		res = res + 1 + i - i
	}
	return res
}

// AppendAtEnd ...
func (x MyList) AppendAtEnd(y MyList) MyList {
	res := x
	for i := range y {
		res = append(res, y[i])

	}
	return res
}

// InsertAnywhere ...
func (x MyList) InsertAnywhere(y MyList, pos int) MyList {
	res := x
	res = append(res[:pos], append(y, res[pos:]...)...)
	return res
}

// ModifySingleElement ...
func (x MyList) ModifySingleElement(y int, pos int) MyList {
	res := x
	res[pos] = y
	return res
}

// RemoveElements ...
func (x MyList) RemoveElements(y int, pos int) MyList {
	res := x
	res = append(res[:pos], res[pos+y:]...)
	return res
}

// RemoveEverything ...
func (x MyList) RemoveEverything() MyList {
	res := x
	res = res[:0]
	return res
}

///////////////////////////////////////////////////////////////////////////////
func main() {

	//create some vars
	var a, b MyList
	for i := 0; i < 5; i++ {
		a = append(a, i)
	}
	for i := 5; i < 10; i++ {
		b = append(b, i)
	}

	var pos, newNumber, inRange int
	newNumber = 10
	pos = 3
	inRange = 2

	fmt.Println("a.GetNumberElements:", a.GetNumberElements())
	fmt.Println("b.GetNumberElements:", b.GetNumberElements())
	fmt.Println("AppendAtEnd        :", a.AppendAtEnd(b))
	fmt.Println("InsertAnywhere     :", a.InsertAnywhere(b, pos))
	fmt.Println("ModifySingleElement:", a.ModifySingleElement(newNumber, pos))
	fmt.Println("RemoveElements     :", a.RemoveElements(inRange, pos))
	fmt.Println("RemoveEverything   :", a.RemoveEverything())

	fmt.Println(a, b)

}
