// main educates compiler to understand that this is being executable.
package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	// returns 2 objects, assigned, type inference occurs
	resp, err := http.Get("http://api.theysaidso.com/qod")
	if err != nil {
		// print to stdout
		fmt.Println(err)
		return
	}
	// clean up ressources after use
	defer resp.Body.Close()
	// func ReadAll(r io.Reader) ([]byte, error)
	content, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(err)
		return
	}
	// type casting byte > string
	fmt.Println(string(content))
}
