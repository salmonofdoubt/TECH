// author: abaumann@google.com
// From go/gonotes, this program addresses questions 7-8
// The proof is in the pudding...

package main

import "fmt"

func main() {

	//7
	//List all files/directories with name = “*atl15*” under directory: “/home/build/google3/platforms/networking/data/model”
	//(Tip: filepath Join() and Glob())
	fmt.Println("\n---7---")

	//8 Using the directory “/home/build/google3/platforms/networking/data/model”:
	// a Count the number of files per file extension. Print the result.
	// b Find duplicate filenames (not consider the directory as part of the filename). Print the result.
	//(Tip: filepath Walk(), Ext(), Base())
	fmt.Println("\n---8a---")

	fmt.Println("\n---8b---")

}

//7

//8a
//8b
