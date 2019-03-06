/*
Anonymous Function
-------------------
# func without a name
e.g.
*/

package main

import "fmt"

func main() {
	x := 0
	increment := func() int {
		x++
		return x
	}

	fmt.Println(increment())
	fmt.Println(increment())
}

/*
package main
import "fmt"

func wrapper() func() int {
// so wrapper func returns another func
	x := 0
	return func() int {
		x++
		return x
	}
}

func main(){
	increment := wrapper()
	//variable is a function
	fmt.Println(increment())
	fmt.Println(increment())
}
*/
