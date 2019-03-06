/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
//// Hash Table Step by Step ////////
/////////////////////////////////////

package main

import "fmt"

/*HashBucket is exported*/
func HashBucket(word string, numberOfBuckets int) int {
	letter := int(word[0])
	bucket := letter % 12 //HashFunction
	return bucket
}

func main() {
	var word string
	fmt.Println("Enter a word: ")
	fmt.Scan(&word)
	fmt.Println("Bucket#: ", HashBucket(word, 12))
}
