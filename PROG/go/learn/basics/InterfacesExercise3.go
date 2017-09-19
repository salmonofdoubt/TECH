//SMIFO
//S Create Structs with relevant fields (a concrete type has methods attached).
//M Create Methods with struct as Receiver. Method names will always be identical.
//I Create Interface associated with Methods M, using Method signatures as field.
//F Create Function that takes the Interface I, returns I.M()
//O Create Objects, use them on the Function F

package main

import "fmt"

//MZ S being the previous model
type MZ struct {
	price, year, deprecation float64
}

//ETZ S being the newer model
type ETZ struct {
	color, ccm float64
}

//M Create respective Methods where these Structs are Receivers (all have identical Function name)
func (m MZ) value() float64 {
	return m.price / (2017 - m.year) * m.deprecation
}

func (m ETZ) value() float64 {
	return m.color * (1 + m.ccm)
}

//I Create Interface associated with Methods, using Function signature as field
type calcValue interface {
	value() float64
}

//F Create a Function that takes the Interface, calling the Method's Function name
func worth(v calcValue) float64 {
	return v.value()
}

//O Create objects, using object on the Function that implements the Interface
func main() {
	myMZ := MZ{price: 3000, year: 200, deprecation: 0.3}
	myETZ := ETZ{color: 2, ccm: 250}

	res1 := worth(myMZ)
	res2 := worth(myETZ)

	fmt.Println(res1, res2, res1+res2)

}
