///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
/////// interface pointer reveicer ////
///////////////////////////////////////

package main

import (
	"fmt"
	"math"
)

type circle struct {
	radius float64
}

type shape interface {
	area() float64
}

//// value receiver: takes a value incl address value info(cir) or info(&cir)
//// go figures that.
//func (c circle) area() float64 {
//// But pointer receiver: only ever takes a pointer to an address info(&cir)
func (c *circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

///////////////////////////////////////////////////
///  Receiver | Value     /////////////////////////
/// --------------------- /////////////////////////
/// t T				| T and *T  /////////////////////////
/// t *T			| only *T   (so, called with &T) ////
///////////////////////////////////////////////////

func info(z shape) { //takes type shape
	fmt.Println("circle area: ", z, z.area()) //method call
}

func main() {
	var x float64
	fmt.Println("Enter circle radius: ")
	fmt.Scan(&x)
	cir := circle{x}
	info(&cir)
}
