/*package main
import "fmt"

var a string = "whoo"

func main(){
	fmt.Println("a - ", a, &a)
}
*/

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

const metersToYards float64 = 1.09361

func convert() {
	var meters float64
	fmt.Println("Enter meters swam: ")
	fmt.Scan(&meters) //scans and listens on stdin
	yards := meters * metersToYards
	fmt.Println("You swam: ", yards, "yards")
}
func main() {
	convert()
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

/*
in go we pass by value, and the value can be a memory address
the proof, however, is in the pudding

package main
import "fmt"

func intPointer(){

	var a int = 43
	fmt.Println(a)	// 43
	fmt.Println(&a)	// a's address is 0xc82000a2b8

	var b *int = &a // b is an 'int pointer', a must be an int
	fmt.Println(b)	// b's value is 0xc82000a2b8

	fmt.Println(&b)	// b's address is 0xc820032028
	fmt.Println(*b)	// b's value 43 "derefenecing"

	*b = 42			// change the value at the address

	fmt.Println(a)	// 42 Thisisocool
	fmt.Println(&a)	// see, a's address is still 0xc82000a2b8same
	//fmt.Println(*a) //oh won't work as 'a' is not a pointer
}

func stringPointer(){

	var s string = "stringent"
	fmt.Println(s, &s)

	var t *string = &s
	fmt.Println(t, &t, *t)
}

func main(){
	intPointer()
	stringPointer()
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main
import "fmt"

func zero(z *int) {		// takes int pointer
	fmt.Println("z  : ", z, "looks like an address!")
	fmt.Println("&z : ", &z, "another address!")
	fmt.Println("*z : ", *z, "value of z, obviously passed from x :)")
	*z = 0
	fmt.Println("*z : ", *z, "new value of z, and therfore that of x")
}

func main(){
	x := 5
	fmt.Println("x  : ",x)
	fmt.Println("&x : ",&x)
	zero(&x) 		//calls zero with address
	fmt.Println("x  : ",x)
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main
import "fmt"

func zero(z *int) {			// takes an int pointer
	fmt.Println("z  : ", z, "looks like an address!")
	fmt.Println("&z : ", &z, "another address!")
	fmt.Println("*z : ", *z, "value of z, obviously passed from x :)")
	*z = 0
	fmt.Println("*z : ", *z, "new value of z, and therfore that of x")
}

func main(){
	x := 5
	fmt.Println("x  : ",x)
	fmt.Println("&x : ",&x)
	zero(&x) //calls zero with x's address
	fmt.Println("x  : ",x)
}

*/
