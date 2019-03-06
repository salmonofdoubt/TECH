/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
/////////// Structs /////////////////
//////////// JSON ///////////////////
///// Marshal/Unmarshal strings /////
//// strings exist in the program ///
/////////////////////////////////////

package main

import (
	"encoding/json"
	"fmt"
)

//Person exported
type Person struct {
	First       string
	Last        string //`json:"that Connolly??"` //tag
	Age         int    //`json:"wisdom score"`    //tag
	notExported int    //not exported
}

func main() {
	p1 := Person{"James", "Connolly", 174, 007} //var of type person with set of fields
	p2 := Person{"Marie", "Courie", 174, 006}
	fmt.Println("p1 :", p1.First, p1.Last, p1.Age, p1.notExported)
	fmt.Println("p2 :", p2.First, p2.Last, p2.Age, p2.notExported)

	bs, _ := json.Marshal(p1) //create a string bytesclice
	fmt.Println(string(bs))

	//unmarshall bs, which holds p1, onto address of p2
	json.Unmarshal(bs, &p2)

	//note that p2.notExported remains
	fmt.Println("p2 :", p2.First, p2.Last, p2.Age, p2.notExported)
}
