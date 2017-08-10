package main

/*
A type with some methods, that's all. No interfaces here.
Note that if receivers are not a pointer, then values apply only during a method call.
Without using pointers, the object remains 0.
*/

import (
	"fmt"
)

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

// The following two methods are wrong for two reasons:
// they ake a whole var, rather than a pointer (expensive)
// plus the setter works on the value in the method, rather than the struct

func (sNode SLLNode) NoPointerSetValue(v int) { // a setter
	sNode.value = v
	fmt.Println("v in method:", v)
}

func (sNode SLLNode) NoPointerGetValue() int { // a getter
	return sNode.value
}

// Just to alloc the new type
func NewSLLNode() *SLLNode {
	return new(SLLNode)
}

func main() {

	sllNode := NewSLLNode() //a new empty node
	sllNode.SetValue(4)
	fmt.Println(sllNode.GetValue())

	sllNode.NoPointerSetValue(44)
	fmt.Println(sllNode.NoPointerGetValue()) // 4 :(
}
