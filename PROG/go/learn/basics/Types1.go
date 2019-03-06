/*
BUILT-IN
int floatXX, string,

USER DEFINED
struct	fields, methods (to work on the type)

type MyList []int // now create methods
methods for adding removing lenght
play.golang.org/p/EhBPBRN17E

*/

package main

import "fmt"

type myList []int

func (x *myList) add(i int) { //method on that particular type
	*x = append(*x, i)
	fmt.Println(*x)
}

func (x *myList) remove(i int) { //method on that particular type
	*x = append((*x)[:i-1], (*x)[i:]...)
	fmt.Println(*x)
}

func (x myList) length() { //method on that particular type
	fmt.Println(len(x))
}

func main() {

	l := myList([]int{1, 2})

	l.add(10)
	fmt.Println("Actually changed:", l)

	l.remove(2)
	fmt.Println("Changed again   :", l)

	l.length()
	fmt.Println("method 'length' does not change anything:", len(l))
}
