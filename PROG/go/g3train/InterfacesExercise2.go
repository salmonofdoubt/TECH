//SMIFO
//S Create Structs with relevant fields (a concrete type has methods attached).
//M Create Methods with struct as Receiver. Method names will always be identical.
//I Create Interface associated with Methods M, using Method signatures as field.
//F Create Function that takes the Interface I, returns I.M()
//O Create Objects, use them on the Function F

package main

import "fmt"

//S, create the structs and their fields
type aubergine struct {
	weight float64
}

type kiwi struct {
	amount float64
}

//M name is what connects the structs
func (a aubergine) price() float64 {
	return 3.2 * a.weight
}

func (k kiwi) price() float64 {
	return 0.5 * k.amount
}

//I, Interface with field of method names
type calcPrice interface {
	price() float64
}

//F, the func that takes the interface
func givenPrice(t calcPrice) float64 {
	return t.price()
}

//O, the objects and how they passed in to the function
func main() {
	myaubergine := aubergine{3.2}
	mykiwi := kiwi{5}

	res := givenPrice(myaubergine) + givenPrice(mykiwi)
	fmt.Println(res)

}
