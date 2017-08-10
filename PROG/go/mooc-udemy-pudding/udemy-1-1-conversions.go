/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
///Rune is a int32, or a char 2^32, 4B///

package main

import "fmt"

func main() {
	for i := 0; i <= 140; i++ {
		fmt.Println(i, " - ", string(i), " - ", []byte(string(i)))
	}
}

/*
/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
package main
import "fmt"

func main(){
	for i := 120; i <= 130; i++{
		fmt.Println(i, " - ", string(i), " - ", []byte(string(i)))
	}
	s := "a"					    	//"" is a string
	fmt.Println(s)					//print new line with s
	fmt.Printf("%T \n", s)	//print new line with format of s

	r := 'a'						    //'' is a rune
	fmt.Println(r, rune(r))	//print a new line with r
	fmt.Printf("%T \n", r)	//print new line with format of r
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////

package main
import "fmt"

func main(){
	for i := 120; i <= 130; i++{
		fmt.Println(i, " - ", string(i), " - ", []byte(string(i)))
	}
	s := "a"						//"" is a string
	fmt.Println(s)					//print new line with s
	fmt.Printf("%T \n", s)			//print new line with format of s

	r := 'a'						//'' is a rune
	fmt.Println(r, rune(r))			//print a new line with r
	fmt.Printf("%T \n", r)			//print new line with format of r

	u := `<>
	Doc String
	  </>`
  	fmt.Println("\n", u)			//`` backticks is a string retaining structure
  	fmt.Printf("%T \n", u)			//print new line with format of u
}
*/
