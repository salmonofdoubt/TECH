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
	"fmt"
	"log"
	"net/http"
	//"io/ioutil"
	"bufio"
	"os"
)

func main() {
	//// http.Get returns two values
	//// Get() has Reponse struct, see docu. One item is Body
	res, err := http.Get("http://www-01.sil.org/linguistics/wordlists/english/wordlist/wordsEN.txt")

	//// if err is not nil, call log.Fatalln with that error
	if err != nil {
		log.Fatalln(err)
	}

	words := make(map[string]string)
	sc := bufio.NewScanner(res.Body) // implements the read close interface
	sc.Split(bufio.ScanWords)

	for sc.Scan() {
		words[sc.Text()] = ""
	}
	if err := sc.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}

	i := 0
	for k := range words {
		fmt.Println(k)
		if i == 100 { // print only so many
			break
		}
		i++
	}
}
