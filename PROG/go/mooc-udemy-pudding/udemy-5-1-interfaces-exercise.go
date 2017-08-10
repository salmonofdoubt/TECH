///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
//////////// INTERFACES  //////////////
//////////// POLYMORHISM //////////////
// An exercise ////////////////////////
// Implement

package main

import "fmt"

//Square defined by its side
type Square struct {
	side float64
}

//Circle defined by it radius
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

//Shape is the INTERFACE that calls the correct method, depending how it is called
//"area() float64" is what Shape implements
type Shape interface {
	area() float64 //if Shape is to be implemented it needs this signature
}

//func takes an interface :)
func info(z Shape) float64 { //takes type shape
	return z.area()
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
that struct assigns 10 to its field 'side'

However, info() takes an interface Shape, which requires area() to execute

area() is a method and wonders which exact method to execute
since its been given Square as a struct, it executes the multiplication

everything being returned
*/
