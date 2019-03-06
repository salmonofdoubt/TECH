///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
//////////// INTERFACES  //////////////
//////////// POLYMORHISM //////////////
///////////////////////////////////////

package main

import "fmt"

//Square defined by its side
type Square struct {
	side float64
}

//Circle defined by its radius
//Also Circle and Square are CONCRETE TYPES since they have methods attached

type Circle struct {
	radius float64
}

//attach a method to Square and Circle
func (z Square) area() float64 {
	return z.side * z.side
}

func (c Circle) area() float64 {
	return c.radius * 2 * 3.14
}

/*
Shape is the INTERFACE, controlling a behaviour but with no further code
It accesses the correct method, depending how it's been called
"area() float64" exactly is what Shape implements, nothing else.
If Shape is to be implemented, it needs this exact signature of a method
like Square, like Circle has.
[-] Also, an interface is an ABSTRACT TYPE, as it has no methods attached
*/
type Shape interface {
	area() float64
}

//func takes an interface :)
func info(z Shape) float64 { //takes type shape
	return z.area() //method call
}

func main() {
	sqr := Square{10}
	fmt.Println(info(sqr))

	cir := Circle{5}
	fmt.Print(info(cir))
}

/*
Backtrace:
main calls info() with sqr, which is a struct Square
that struct has been assigned 10 to its field 'side'

info() takes it as an interface Shape
interface Shape then holds a method call area() to execute

so area() is a method and wonders which exact method to execute
since its been given Square as a struct, it executes the multiplication

everything being returned
*/
