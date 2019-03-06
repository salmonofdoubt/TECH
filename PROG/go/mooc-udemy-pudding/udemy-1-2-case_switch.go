/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main

import "fmt"

func swtch(x int) {
	switch x {
	case 1, 2:
		fmt.Println("Invoked case x=1 or x=2")
	case 3, 4:
		fmt.Println("Invoked case x=3 or x=4")
	default:
		fmt.Println("fall through")
	}
}

func main() {
	var x int
	fmt.Println("Enter number: ")
	fmt.Scan(&x)
	fmt.Println("Got ", x, "from stdin", "\n", "handing it to another function..")
	swtch(x)
}

/*
/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main
import "fmt"

func switch(x interface{}){ 		//x could be anything
	switch x.(type) {
	case int:
		fmt.Println("Got ", x, " -- an int")
	case string:
		fmt.Println("Got ", x, " -- a string")
	default:
		fmt.Println("fall through")
	}
}

func main(){
	swtch(7)
	swtch("Andre")
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main
import "fmt"

type Contact struct {			// needs to be declared outside of function
	greeting string
	name string
}

type Pair struct {
	left string
	right string
}

func tellmetype(x interface{}){ 	//x could be anything
	switch x.(type) {
	case int:
		fmt.Println("Got ", x, " -- an int")
	case string:
		fmt.Println("Got ", x, " -- a string")
	case Contact:
		fmt.Println("Got ", x, " -- a contact")
	case Pair:
		fmt.Println("Got ", x, " -- a pair")
	default:
		fmt.Println("fall through")
	}
}

func main(){

	var Baumi = Contact {"Mr.", "Baumann"}
	var socks = Pair {"green", "blue"}

	tellmetype(7)
	tellmetype("Andre")
	tellmetype(Baumi)
	tellmetype(socks)
}
*/
