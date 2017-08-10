package main

import (
	"factoryPattern/appliances" //under src/
	"fmt"
)

func main() {
	fmt.Println("Enter preferred appliance type")
	fmt.Println("0: Stove")
	fmt.Println("1: Fridge")
	fmt.Println("2: Microwave")

	var myType int
	fmt.Scan(&myType)
	fmt.Println("Input was:", myType)

	myAppliance, err := appliances.CreateAppliance(myType) // the iota

	if err == nil {
		myAppliance.Start()
		fmt.Println(myAppliance.GetPurpose())
	} else {
		fmt.Println(err)
	}
}
