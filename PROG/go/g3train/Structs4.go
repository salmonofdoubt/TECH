// author: abaumann@google.com
// From go/gonotes HWK Dec 05 2016

/*
Pointers, Structs (Part II)
Exercises:
Continuing HWK 2 with exercise of routers below:

Write a router method to modify the Network a router belongs to.
Write a router method to modify the description of a given port.

For both exercises, write the same method using a pointer/no pointer as
a receiver and see the differences.
*/

package main

import "fmt"

// Port struct defines fields used in Router struct
type Port struct {
	Name, Desc string
}

// Router struct defines router fields and inherits Port struct fields
type Router struct {
	Name, Network, Vendor string
	Ports                 []Port
}

// RouterName is a Router method
func (r Router) RouterName() string {
	return r.Name
}

//RouterNetwork ...
func (r Router) RouterNetwork() string {
	return r.Network
}

//RouterVendor ...
func (r Router) RouterVendor() string {
	return r.Vendor
}

//RouterPorts ...
func (r Router) RouterPorts() []Port {
	return r.Ports
}

// ChangeNetwork is a Router method that modifies the Network
func (r Router) ChangeNetwork() string {
	r.Network = "B4"
	fmt.Println("Inside ChangeNetwork()......:", r)
	return r.Network
}

// ChangeNetworkPtr is a Router method that modifies the Network using a pointer
func (r *Router) ChangeNetworkPtr() string {
	r.Network = "B4"
	fmt.Println("Inside ChangeNetworkPtr()...:", *r)
	return r.Network
}

// ChangePort is a Router method, modifies Port
// Observation: When working / returning a struct type it makes no
// difference whether the method's receiver is a pointer or not.
// The object will be changed permanently either way:
func (r Router) ChangePort() []Port {
	newPort := Port{"NEWPORT", "BERT"}
	for i := range r.Ports {
		r.Ports = append(r.Ports[:i], newPort)
	}
	fmt.Println("Inside ChangePort().........:", r)
	return r.Ports
}

// ChangePortPtr is a Router method, modifies Port using pointer
func (r *Router) ChangePortPtr() []Port {
	newPort := Port{"NEWPORT", "BERT"}
	for i := range r.Ports {
		r.Ports = append(r.Ports[:i], newPort)
	}
	fmt.Println("Inside ChangePortPtr()......:", *r)
	return r.Ports
}

func main() {
	// Initialize one Object
	P1R1 := Port{"xe-0/1/0", "TEST"}
	P2R1 := Port{"xe-0/0/1", "Desc1"}
	R1 := Router{"bb01.mad06", "B2", "Juniper", []Port{P1R1, P2R1}}

	// Invoke previous Router methods
	fmt.Println("R1.RouterName()   :", R1.RouterName())
	fmt.Println("R1.RouterNetwork():", R1.RouterNetwork())
	fmt.Println("R1.RouterVendor() :", R1.RouterVendor())
	fmt.Println("R1.RouterPorts()) :", R1.RouterPorts())
	fmt.Println("All R1 fields     :", R1.Name, R1.Network, R1.Vendor, R1.Ports)

	// Invoke new Router methods
	fmt.Println("\n...")
	R1.ChangeNetwork()
	fmt.Println("Outside ChangeNetwork().....:", R1)
	R1.ChangeNetworkPtr()
	fmt.Println("Outside ChangeNetworkPtr()..:", R1)

	fmt.Println("\n...")
	R1.ChangePort()
	fmt.Println("Outside ChangePort()........:", R1)
	R1.ChangePortPtr()
	fmt.Println("Outside ChangePortPtr().....:", R1)
}

// end of main()
