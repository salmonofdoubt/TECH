package main

import (
	"errors"
	"fmt"
)

var ErrInvalidNode = errors.New("Node is not valid")

type Node interface {
	SetValue(v int) error
	GetValue() int
}

//type SLLNode
type SLLNode struct {
	next         *SLLNode
	value        int
	SNodeMessage string //unique message to SSLNode, see constructor
}

func (sNode *SLLNode) SetValue(v int) error {
	if sNode == nil {
		return ErrInvalidNode // an error var
	}
	sNode.value = v
	return nil
}

func (sNode *SLLNode) GetValue() int {
	return sNode.value
}

//constructor
func NewSLLNode() *SLLNode {
	return &SLLNode{SNodeMessage: "This is a message from the normal Node"}
}

//type PowerNode
type PowerNode struct {
	next         *PowerNode
	value        int
	PNodeMessage string //unique message to PowerNode, see constructor
}

func (sNode *PowerNode) SetValue(v int) error {
	if sNode == nil {
		return ErrInvalidNode //receiver can be nil
	}
	sNode.value = v * 10
	return nil

}

func (sNode *PowerNode) GetValue() int {

	return sNode.value
}

//constructor
func NewPowerNode() *PowerNode {
	return &PowerNode{PNodeMessage: "This is a message from the power Node"}
}

func main() {

	var n Node // n is type of Interface, as such useless

	// case1:
	//n = &SLLNode{} // better case, resembles a struct

	// case2: demonstrates receiver can be nil
	var sllnode *SLLNode
	n = sllnode // this will cause error "Node is not valid"

	fmt.Println(n.SetValue(4))

	// demonstrate type switching
	n = createNode(5)

	switch cn := n.(type) {
	case *SLLNode:
		fmt.Println("Type is SLLNode, message:", cn.SNodeMessage)
	case *PowerNode:
		fmt.Println("Type is PowerNode, message:", cn.PNodeMessage)
	}

	sNode := &SLLNode{} // method is a pointer receiver, not value receiver
	n = sNode

	n.SetValue(4)
	fmt.Println(n.GetValue())

}

// simulates a SLLNode being ceated
func createNode(v int) Node { // node being T interface
	sn := NewPowerNode()
	sn.SetValue(v)
	return sn
}
