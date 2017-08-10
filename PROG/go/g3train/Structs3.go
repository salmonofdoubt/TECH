// author: abaumann@google.com
// From go/gonotes 28/11/16, HWK 2 routers

/*
a) Define the types: Router and Port.
DONE
b) Define a Router method that returns the value of each field. Create a method per field.
DONE
c) Create a router bb01.mad06. Print the struct. Test each one of the methods.
DONE
d) Write a function that returns a slice with the routers in table above.
Function signature → func routers() []Router
DONE
e) Write the function “Vendor” that takes a vendor name and a list of routers and returns the routers of the given vendor. If no vendor or routers are provided when calling the function, it should return an error.
f) Write the function “Network” that takes a list of routers and returns the number of routers per network.
g) Write the function “Test” that takes a list of routers and returns a map with router name as a key. The value is a slice of ports with “TEST” description.

*/
package main

import (
	"errors"
	"fmt"
)

// a) Define types, using structs
type Port struct {
	Name, Desc string
}

// Router inherits an array of Port structs
type Router struct {
	Name, Network, Vendor string
	Ports                 []Port
}

// b) create relevant Router methods, called from main()
func (r Router) RouterName() string {
	return r.Name
}

func (r Router) RouterNetwork() string {
	return r.Network
}

func (r Router) RouterVendor() string {
	return r.Vendor
}

func (r Router) RouterPorts() []Port {
	return r.Ports
}

func main() {
	//declare the objects
	P1R1 := Port{"xe-0/1/0", "TEST"}
	P2R1 := Port{"xe-0/0/1", "Desc1"}
	R1 := Router{"bb01.mad06", "B2", "Juniper", []Port{P1R1, P2R1}}

	P1R2 := Port{"xe-1/1/1", "Desc2"}
	P2R2 := Port{"xe-2/2/1", "TEST"}
	R2 := Router{"bb02.mad06", "B2", "Juniper", []Port{P1R2, P2R2}}

	P1R3 := Port{"et-1/1/1", "Desc3"}
	R3 := Router{"csj11.bru06", "Jupiter", "Brocade", []Port{P1R3}}

	P1R4 := Port{"et-1/1", "TEST"}
	P2R4 := Port{"et-1/2", "Desc4"}
	P3R4 := Port{"et-1/3", "Desc5"}
	R4 := Router{"csm11.nrt14", "Minicluster", "Arista", []Port{P1R4, P2R4, P3R4}}

	// optional: print these objects
	//fmt.Println("\n", R1, "\n", R2, "\n", R3, "\n", R4)

	// b) using Router methods
	fmt.Println("R1.RouterName()   :", R1.RouterName())
	fmt.Println("R1.RouterNetwork():", R1.RouterNetwork())
	fmt.Println("R1.RouterVendor() :", R1.RouterVendor())
	fmt.Println("R1.RouterPorts()) :", R1.RouterPorts())
	fmt.Println("Just fields of R1 :", R1.Name, R1.Network, R1.Vendor, R1.Ports, "\n")

	// d) call sliceOfRouters() function
	fmt.Println("sliceOfRouters():", sliceOfRouters(R1, R2, R3, R4))

	// e) call givenVendor() function
	allRouters := []Router{R1, R2, R3, R4}
	fmt.Println("empty.......:", givenVendor("", allRouters))
	fmt.Println("Brocades....:", givenVendor("Brocade", allRouters))
	fmt.Println("Aristas.....:", givenVendor("Arista", allRouters))
	fmt.Println("Junipers....:", givenVendor("Juniper", allRouters))

	// f) call routersPerNetwork() function
	fmt.Println("routersPerNetwork...:", routersPerNetwork(allRouters))

	// g) call Test() function
	fmt.Println("Test():", Test(allRouters))
}

//	d)	Function sliceOfRouters() returns a slice with the routers in the table
func sliceOfRouters(r ...Router) []Router {
	var res []Router
	for _, v := range r {
		res = append(r, v)
	}
	return res
}

//	e)	Function vendor() takes vendor name and a list of routers.
//			Returns the routers of given vendor. If no vendor or routers, return an error.
func givenVendor(vendorname string, routers []Router) []string {
	var res []string
	if vendorname == "" {
		errors.New("vendorname is empty")
	} else {
		for i := range routers {
			if routers[i].Vendor == vendorname {
				res = append(res, routers[i].Name)
			}
		}
	}
	return res
}

//	f)	Write function “Network”. Takes list of routers. Returns number of routers per network.
func routersPerNetwork(routers []Router) map[string]int32 {
	networkMap := map[string]int32{
		"B2":          0,
		"B4":          0,
		"Jupiter":     0,
		"Minicluster": 0,
	}

	for i := range routers {
		if routers[i].Network == "B2" {
			networkMap["B2"] = +1
		} else if routers[i].Network == "B4" {
			networkMap["B4"] = +1
		} else if routers[i].Network == "Jupiter" {
			networkMap["Jupiter"] = +1
		} else if routers[i].Network == "Minicluster" {
			networkMap["Minicluster"] = +1
		} else {
			fmt.Println("new or unknown network")
		}
	}
	return networkMap
}

// Test will check for any interfaces in Testing
// Write function “Test”. Takes list of routers.
// Returns map with router name as a key,
// Value is slice of ports with “TEST” description).
// Not sure what to do here
func Test(routers []Router) map[string][]Port {
	routerNamesTest := make(map[string][]Port)
	fmt.Println(routerNamesTest)
	for i := range routers {
		if routers[i].Ports.Desc == "TEST" {
			routerNamesTest[i] = routers.Name
		}
	}
	return routerNamesTest
}
