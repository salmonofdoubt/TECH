/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
////////// Hash Tables //////////////
/////////////////////////////////////

/*
<word> - <definition>

* unsorted              -> slow
* sorted                -> quicker
* categories, buckets   -> fast, right in X bucket, uneven distribution
* hash algo             -> word > hashed > bucketed XYZ (evenenly distributed,
                           unsorted, can be sorted, super fast, )
*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"net/http"
)

//HashBucket just returns int of the first letter of the word[0] worst distribution
func HashBucket(word string) int {
	return int(word[0])
}

func main() {
	//http.Get returns two values
	//Get() has Reponse struct, see docu. One item is Body
	res, err := http.Get("http://www.gutenberg.org/files/2701/old/moby10b.txt")
	//if err is not nil, call log.Fatalln with that error
	if err != nil {
		log.Fatalln(err)
	}
	//scan that page. (res.Body) implements the read close interface
	scanner := bufio.NewScanner(res.Body)
	defer res.Body.Close() //defers this to the end of main

	//Set split function for the scanning operation
	scanner.Split(bufio.ScanWords)

	//Create slice to hold counts
	buckets := make([]int, 200)

	//loop over the words. which bucket has how many entries starting A, B, C..
	//very uneven
	for scanner.Scan() {
		n := HashBucket(scanner.Text()) // declared above main
		buckets[n]++
	}
	fmt.Println(buckets[65:122])
	fmt.Println("*****breakdown******:")
	for i := 65; i < 123; i++ {
		fmt.Printf("%v - %c - %v \n", i, i, buckets[i])
	}
}
