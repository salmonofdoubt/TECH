package main

import (
	"fmt"
	"reflect"
	"sort"
)

// demonstrates using native sort.interface with an implementation

// concrete type
type Col []string

func (m Col) Len() int {
	return len(m)
}

func (m Col) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m Col) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

// end concrete type

func main() {

	seq := Col{"N", "S", "A"}

	fmt.Println(seq)
	fmt.Println(reflect.TypeOf(seq))

	//inPlace operation, so this has changed the object
	sort.Sort(seq) //remember Sort() takes "Interface" that is defined by 3 methods

	fmt.Println(seq)
}
