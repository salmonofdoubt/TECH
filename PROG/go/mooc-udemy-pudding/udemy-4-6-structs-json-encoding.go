///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
///////////// Structs /////////////////
////////////// JSON ///////////////////
////// encoding/decoding stream ///////
// stream is in/output from file/web //
///////////////////////////////////////

package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

//Person exported
type Person struct {
	First    string
	Last     string //`json:"that Connolly??"` //tag
	Age      int    //`json:"wisdom score"`    //tag
	Exported int    //exported
}

func main() {
	p1 := Person{"James", "Connolly", 174, 007} //var of type person with set of fields
	fmt.Println("Person p1: ", p1)

	/*json.NewEncoder(os.Stdout) *Encoder
	from json, type Encoder implements NewEnconder
	NewEncoder takes a writer, a file (os.Stdout) which returns a pointer
	So with a pointer to Encoder all its methods are available
	so we call the method with dot notation .Encode()
	*/
	json.NewEncoder(os.Stdout).Encode(p1) //encoded stream of p1, outputs to terminal
	/*
		assigning this to a var won't work. Maybe a buffer would work?
		ls -la /dev/stdout
		lr-xr-xr-x  1 root  wheel  0 Sep 29 17:36 /dev/stdout -> fd/1
		sudo fs_usage | grep udemy
	*/

	//tweak: lets create a Psyeudo stream (from a a string)
	rdr := strings.NewReader(`{"First":"Psyeudo", "Last":"Smith", "Age":100}`)
	fmt.Println("Stream :", rdr) //curious

	json.NewDecoder(rdr).Decode(&p1) //
	fmt.Println(p1)
}
