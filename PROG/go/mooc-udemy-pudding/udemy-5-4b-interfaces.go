///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
///////// EMPTY INTERFACE /////////////
//// Benefit: single access, say to print ////

package main

import "fmt"

type vehicles interface{} //empty interface, no methods

type vehicle struct {
	Seats    int
	MaxSpeed int
	Color    string
}

type car struct {
	vehicle
	Wheels int
	Doors  int
}

type plane struct {
	vehicle
	Jet bool
}

type boat struct {
	vehicle
	Length int
}

func main() {
	//As long as nothing is initialised, nothing is truly inherited. Lets do this once:
	prius := car{ //object is of type car
		vehicle: vehicle{ //inherits everything from vehicle
			Seats:    4, //initialises those fields from vehicle
			MaxSpeed: 160,
			Color:    "green",
		},
		Wheels: 4, //initialises own fields isted in car
		Doors:  2,
	}
	tacoma := car{}
	cars := []car{prius, tacoma} //a slice of car objects

	//for key, value := range cars {
	//	fmt.Println(key, " - ", value)
	//}

	boeing747 := plane{
		vehicle: vehicle{
			Seats:    16, //initialises those fields from vehicle
			MaxSpeed: 960,
			Color:    "silver",
		},
		Jet: true,
	}
	boeing757 := plane{}
	planes := []plane{boeing747, boeing757}

	//for key, value := range planes {
	//	fmt.Println(key, " - ", value)
	//}

	sanger := boat{
		vehicle: vehicle{
			Seats:    32,
			MaxSpeed: 35,
			Color:    "white",
		},
		Length: 23,
	}
	nautique := boat{}
	boats := []boat{sanger, nautique}

	//for key, value := range boats {
	//	fmt.Println(key, " - ", value)
	//}

	//using the interface "vehicles" one can access all objects through,
	//hence commenting out individual print commands above
	//rides := []vehicles{prius, tacoma, boeing747, boeing757, sanger, nautique}
	rides := []vehicles{cars, planes, boats}
	for key, value := range rides {
		fmt.Println(key, "-", value)
	}
}
