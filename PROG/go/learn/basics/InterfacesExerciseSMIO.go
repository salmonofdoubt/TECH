package main

// SMIO
// author: abaumann@google.com

/*** SMIFO vs SMIO ************************************************************

S  Structs with relevant fields.

	type S struct{
		...
		}

M  Methods with struct/type as receiver.
   For diff s/t, some method names would be equal, their code different.

func (s S) M(t T) T {
		...magic
}

I  Interface associated with Methods M, using M signatures as field.

	type I interface{
		M(t T) T
	}


F  Function takes I, returns I.M()

	func F(i I) i.M {
		return i.M()
	}

O  Create Objects, use them on the Function F(O)

	O := S{}
	F(O)

-------------------------------------------------------------------------------
O  When not using a F, create Objects of type Interface,
   and use Objects by calling relevant methods

	var O I
	O = S{}
	O.M()

******************************************************************************/

import (
	"fmt"
	"math"
)

type cube struct {
	length float64
}

type sphere struct {
	diameter float64
}

func (l cube) volume() float64 {
	res := math.Pow(l.length, 3)
	return res
}

func (d sphere) volume() float64 {
	return 4 / 3 * math.Pi * math.Pow(d.diameter/2, 3)
}

type calcVolume interface {
	volume() float64
}

func main() {

	var cub calcVolume
	cub = cube{3.01}

	var sph calcVolume
	sph = sphere{7.5}

	// 6. Use Function that implements the Interface
	fmt.Println("volume cub:", cub.volume())
	fmt.Println("volume sph:", sph.volume())

}
