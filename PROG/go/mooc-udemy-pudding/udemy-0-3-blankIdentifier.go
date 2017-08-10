package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	res, _ := http.Get("http://www.spiegel.de")
	// no error checking please
	page, _ := ioutil.ReadAll(res.Body)
	// no error checking please
	res.Body.Close()
	fmt.Printf("%s", page)
}

/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
/*
package main

import "fmt"

func concat(item ...string) string { //variadic function: takes any number the type, and creates a sclice, here: returns single string
	fmt.Println(item, len(item))
	fmt.Printf("%T", item)
	fmt.Println(" --- \"item\" is a slice --- a slice of strings")

	nstring := ""
	for _, v := range item { //that's because range is a KV pair (index, value) where index is being made a blank identifier
		nstring += v
	}
	return nstring
}

func main() { //entry point to program, never has a receiver
	fmt.Println(concat("A", "B", "C", "2", "Many!")) //elements are type 'kind'
}
*/
