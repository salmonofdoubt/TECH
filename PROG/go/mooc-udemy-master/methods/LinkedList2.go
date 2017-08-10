package main

/*
Two structs, doing slightly different things.
They are made

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
)

// SLLNode is the first type with methods
type SLLNode struct {
	next  *SLLNode
	value int
}

func (sNode *SLLNode) SetValue(v int) { // a setter
	sNode.value = v
}

func (sNode *SLLNode) GetValue() int { // a getter
	return sNode.value
}

func NewSLLNode() *SLLNode { // Alloc via built-in new()
	return new(SLLNode)
}

// PLLNode is the second type with methods
type PLLNode struct {
	next  *PLLNode
	value int
}

func (pNode *PLLNode) SetValue(v int) { // a setter
	pNode.value = v * 10
}

func (pNode *PLLNode) GetValue() int { // a getter
	return pNode.value
}

func NewPLLNode() *PLLNode { // Alloc via built-in new()
	return new(PLLNode)
}

type Node interface {
	SetValue(v int)
	GetValue() int
}

func main() {

	var sllNode Node       // SMIO, no F here. So we make O type I.
	sllNode = NewSLLNode() // a constructor
	sllNode.SetValue(4)
	fmt.Println(sllNode.GetValue())

	var pllNode Node
	pllNode = NewPLLNode()
	pllNode.SetValue(4)
	fmt.Println(pllNode.GetValue())

	// Test to see if an implementer <here *SLLNode> implements an interface <that of sllNode>
	if n, ok := sllNode.(*SLLNode); ok { // and only when ok
		fmt.Println("Yo", n.value)
	}
}
