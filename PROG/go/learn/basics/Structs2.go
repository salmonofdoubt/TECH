// author: abaumann@google.com
// From go/gonotes 28/11/16, HWK 1b

/*
Calculate the area of a rectangle:
Define a type Point and a type Rectangle with contains two Points.
Write a Rectangle method that returns the area of the rectangle.
*/

package main

import (
	"fmt"
	"math"
)

type point struct {
	x, y float64
}

type rectangle struct {
	p1, p2 point
}

func (r rectangle) area() float64 {
	l := r.p1.x - r.p2.x
	w := r.p1.y - r.p2.y
	return math.Abs(l * w)
}

func main() {
	coord1 := point{1, 2}
	coord2 := point{1.1, 3}
	fmt.Println("rectangle coordinates x y:", coord1, coord2)

	r := Rectangle{coord1, coord2}
	fmt.Println("resulting rectangle area :", r.area())
}
