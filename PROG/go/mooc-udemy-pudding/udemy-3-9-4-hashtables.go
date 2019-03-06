/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////////// Hash Tables //////////////
/////////////////////////////////////

package main

import (
	"bufio"
	"fmt"
	"log"
	"net/http"
)

func main() {
	//get Moby Dick
	//Oh, this returns two values. Get() has Reponse struct, of which one item is Body
	res, err := http.Get("http://www.gutenberg.org/files/2701/old/moby10b.txt")
	if err != nil {
		log.Fatal(err)
	}
	//scan the page
	//NewScanner takes a reader. res.Body implements the reader interface
	scanner := bufio.NewScanner(res.Body)
	defer res.Body.Close()

	//use Split function for scanning operation
	scanner.Split(bufio.ScanWords)

	//loop over the words, for as long as is true
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}
}
