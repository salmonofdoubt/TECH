package main

import "fmt"

/*
Just to re-iterate the fact that methods can be used with any type
*/

type ShieldLevel int

func (lv *ShieldLevel) RaiseShield(i int) {

	if *lv == 0 {
		*lv = *lv + 1
	}
	*lv = *lv * ShieldLevel(i) //type casting int > Shieldlevel necessary
}

func main() {

	newShieldLevel := new(ShieldLevel)

	seq := []int{2, 4, 3}

	for _, v := range seq {
		newShieldLevel.RaiseShield(v)
		fmt.Println(*newShieldLevel)
	}
}
