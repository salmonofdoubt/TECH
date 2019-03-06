////////////////////////////////////////////////////////////////////////////////
//////////////////// The proof is in the pudding ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////// PBV where Value may be an address /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
///// Not using pointers: many copies of potentially large code ////////////////
mem 								Value
----------------------------------------
1  								  42 (x in main)
.
.
4    								42 (n in func being called)
.
.
//// Using pointers ////////////////////////////////////////////////////////////
mem		 						 	Value
-----------------------------------------
0xc82000a298		    42
(&age in main)			(age in main)
(or *a in changeVal)
.             \_
.               \_
.              		\_
.                   \
0xc820026028   			0xc82000a298
(&a in changeVal)		(a in changeVal)
.                 	(a being an int pointer)
.
*/

package main

import "fmt"

func changeVal(a *int) { //takes an int pointer to a mem addres
	fmt.Println("a *int BEFORE: mem addr:", &a, ", value:", *a, "a:", a)
	*a *= 2 //change the value pointed at
	fmt.Println("a *int BEFORE: mem addr:", &a, ", value:", *a, "a:", a)
}

func main() {
	age := 42
	fmt.Println("ORIGINAL AGE:  mem addr:", &age, ", value:", age)
	changeVal(&age) //pass a mem addr
	fmt.Println("CHANGED AGE :  mem addr:", &age, ", value:", age)
	fmt.Println("value age was changed by pointing to another value and outside its scope.")
}
