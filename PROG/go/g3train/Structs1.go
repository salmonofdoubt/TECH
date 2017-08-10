// author: abaumann@google.com
// From go/gonotes 28/11/16, this program addresses questions 1a

package main

import (
	"fmt"
	"math"
)

//create struct
type circle struct {
	x, y, r float64
}

//couple of methods that work only with that struct as receiver
func (c circle) circ() float64 {
	//             ... * c(type circle).r(a field representing the radius)
	res := 2 * math.Pi * c.r
	return res
}

func (c circle) area() float64 {
	res := math.Pi * c.r * c.r
	return res
}

func main() {
	//create an object
	var c circle
	//not even using coordinates x and y since no method is asking for them...
	c = circle{r: 10}

	//invoke methods on object (do something with them)
	fmt.Println("Circ:", c.circ())
	fmt.Println("Area:", c.area())
}
