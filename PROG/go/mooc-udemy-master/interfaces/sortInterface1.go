package main

import (
	"fmt"
	"sort"
)

// demonstrates using native sort.interface with an implementation

// concrete type
type Article struct {
	Name string
}

type Collection []Article

func (c Collection) Len() int {
	return len(c)
}

func (c Collection) Less(i, j int) bool {
	return c[i].Name < c[j].Name
}

func (c Collection) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

// end concrete type

//creator function
func NewCollection() *Collection {
	return new(Collection)
}

func InPlaceSort(s Collection) {
	sort.Sort(s)
}
func main() {

	item := Collection{{Name: "itemE"}, {Name: "itemA"}, {Name: "itemB"}}

	fmt.Println(item)
	InPlaceSort(item)
	fmt.Println(item)

}
