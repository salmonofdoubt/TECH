package main

import (
	"factoryPattern/situations"
	"fmt"
	"log"
)

func main() {

	fmt.Println("Enter *integer* for state, *rune* for quit ")
	fmt.Println("0: InTransition")
	fmt.Println("1: TransitionDone")
	fmt.Println("2: TransitionFailed")
	fmt.Println("3: OtherGjobAwesome")
	fmt.Println("4: OtherGjobNotGood")
	fmt.Println("5: NoSabbatical")

	var action int
	for {
		if _, err := fmt.Scan(&action); err != nil {
			log.Print("Quit due to non-integer, ", err)
			return
		}

		mySituation, err := situations.CreateSituation(action) // the iota
		fmt.Println("Entered:", action, "This is your plan:")

		if err == nil {
			mySituation.Start()
			fmt.Println(mySituation.GetAction())
		} else {
			fmt.Println(err)
		}
	}

}
