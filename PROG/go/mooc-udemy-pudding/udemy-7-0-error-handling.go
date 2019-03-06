///////////////////////////////////////////
//// The proof is in the pudding //////////
///////////////////////////////////////////
//// Error handling & multiple returns ////
///////// previously foregone /////////////
///////////////////////////////////////////

package main

import (
	"fmt"
	"log"
	"os"
)

//on program start func init() will be read once, although it's not explicitly
//called by main(). Receives / returns nothing
//here we do a sort of setup
func init() {
	nf, err := os.Create("udemy-7-0-error-handling-log.txt")
	if err != nil {
		fmt.Println(err)
	}
	log.SetOutput(nf)
}

func main() {
	_, err := os.Open("nothing.txt")
	if err != nil {
		//fmt.Println("'err happened'", err)
		//log.Println("err happened", err) //
		//log.Fatalln(err)
		panic(err) //shows stack information
	}

}
