////////////////////////////////////////////////////////////////////////////////
//////////////////// The proof is in the pudding ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////// PBV where Value may be an address /////////////////////////////
////////// Change a value by passing the address of it /////////////////////////
////////////////////////////////////////////////////////////////////////////////

package main

import "fmt"

func change1(a int) { //takes an int
	fmt.Println("simply passed value  a      :", a)
	fmt.Println("mem address of  a (&a)      :", &a)
	a = 24
	fmt.Println("value  a  changed           :", a)
	fmt.Println("mem address  a (&a) remains :", &a)
}

func change2(b *int) { //takes an int pointer, so must be an address
	fmt.Println("\n\npassed *int pointer  b  points to address     :", b)
	fmt.Println("this address stores value (*b)                :", *b)
	fmt.Println("mem address of *int pointer  b (&b) itself    :", &b)
	*b = 24 // points to value 24 now
	fmt.Println("\n*int pointer  b  now points to address        :", b)
	fmt.Println("this address now stores value (*b)            :", *b)
	fmt.Println("mem address of *int pointer  b (&b) unchanged :", &b)
}

func main() {
	change1(44)
	age := 44
	fmt.Println(" age after change1() run     :", age)
	change2(&age) // Passing the address of age
	fmt.Println("\n", "age after change2() run,", "\n", "it changed outside its scope:", age)
}
