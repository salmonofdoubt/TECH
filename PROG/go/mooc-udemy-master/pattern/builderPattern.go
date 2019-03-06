package main

import (
	"builderPattern/shieldBuilder"
	"fmt"
)

func main() {
	builder := shieldBuilder.NewShieldBuilder()
	myShield := builder.RaiseLeft().RaiseFront().Build() //Action, Action, only then Build the object
	fmt.Printf("%+v \n", *myShield)                      // {front:true back:false right:false left:true}
}
