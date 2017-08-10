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

//HashBucket comment
func HashBucket(word string, buckets int) int {
	letter := int(word[0])
	bucket := letter % buckets
	return bucket
}

func main() {
	//// http.Get returns two values
	//// Get() has Reponse struct, see docu. One item is Body
	res, err := http.Get("http://www.gutenberg.org/files/2701/old/moby10b.txt")

	//// if err is not nil, call log.Fatalln with that error
	if err != nil {
		log.Fatalln(err)
	}
	// scan that page. (res.Body) implements the read close interface
	scanner := bufio.NewScanner(res.Body)
	defer res.Body.Close() // defers this to the end of main

	// Set split function for the scanning operation
	scanner.Split(bufio.ScanWords)

	// Create slice to hold counts
	buckets := make([]int, 200)

	// loop over the words. which bucket has how many entries starting A, B, C..
	// very uneven
	for scanner.Scan() {
		n := HashBucket(scanner.Text(), 12) // declared above main, now 12 buckets
		buckets[n]++
	}
	fmt.Println(buckets)
	fmt.Println("*****breakdown******:")
	for i := 0; i < 12; i++ {
		fmt.Printf("%v - %v \n", i, buckets[i])
	}
}
