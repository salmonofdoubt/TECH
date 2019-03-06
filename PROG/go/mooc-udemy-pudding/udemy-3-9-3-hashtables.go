/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////////// Hash Tables //////////////
/////////////////////////////////////

package main

import (
	"fmt"
	"io/ioutil"
	// "log"
	"net/http"
)

func main() {
	//returns two values. Get() has Reponse struct, of which one item is Body
	res, _ := http.Get("http://www.gutenberg.org/files/2701/old/moby10b.txt")
	//res, _ := http.Get("http://www.google.com/")

	//reads every byte
	bs, _ := ioutil.ReadAll(res.Body)
	res.Body.Close()
	//so ReadAll gets bytes
	//print bytes
	fmt.Println(bs)
	fmt.Println(string(bs))
}
