package main

import "fmt"

type guinea struct {
	a, b int
}

func (m guinea) NoPointer() {
	m.a = 5
	m.b = 7
}

func (m *guinea) Pointer() { //this actually changes the object passed
	m.a = 5
	m.b = 7
}

func intchange(i *int) int {
	res := *i - 1
	return res
}

func main() {
	m := guinea{0, 0} //new object
	fmt.Println("New object:", m)

	m.NoPointer()
	fmt.Println("NoPointer: ", m) //{0,0}

	//...strangely, with structs, we don't have to pass as address (if receiving func takes a pointer)...
	m.Pointer()
	fmt.Println("Pointer:   ", m) //{5,7}

	//...whilst a non-struct needs to be passed as address (if receiving func takes a pointer)
	i := 1
	fmt.Println("With integer:", intchange(&i)) //...whilst a non-struct needs to be passed as address to
}
