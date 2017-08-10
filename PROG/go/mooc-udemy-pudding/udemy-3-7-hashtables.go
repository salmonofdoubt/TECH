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
* hash algo             -> word > hashed > bucketed XYZ (evenenly distributed,                             unsorted, can be sorted, super fast, )
*/

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {
	//// http.Get returns two values
	//// Get() has Reponse struct, see docu. One item is Body
	res, err := http.Get("http://www-01.sil.org/linguistics/wordlists/english/wordlist/wordsEN.txt")

	//// if err is not nil, call log.Fatalln with that error
	if err != nil {
		log.Fatalln(err)
	}

	//// blank identifier
	bytes, _ := ioutil.ReadAll(res.Body)

	//// convert bs to a string
	str := string(bytes)
	fmt.Println(str)
}
