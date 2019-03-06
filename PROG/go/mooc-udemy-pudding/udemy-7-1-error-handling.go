///////////////////////////////////////////
//// The proof is in the pudding //////////
///////////////////////////////////////////
//// Error handling & multiple returns ////
//// No try /catch ////////////////////////
//// golint to exlude silly mistakes //////

package main

import (
	"fmt"
	"log"
)

//
type norgateMathError struct {
	lat, long string
	err       error
}

func (n *norgateMathError) Error() string { //attach method attached to the struct
	return fmt.Sprintf("norgat math error occured: %v %v %v", n.lat, n.long, n.err)
}

func sqrt(f float64) (float64, error) {
	if f < 0 {
		nme := fmt.Errorf("norgate math redux: square root of negative number: %v", f)
		return 0, &norgateMathError{"50 N", "99 W", nme} //second return
	}
	//implementation
	return 42, nil
}

func main() {
	_, err := sqrt(-10.23)
	if err != nil {
		//fmt.Println("'err happened'", err)
		log.Println("err happened", err) //
		//log.Fatalln(err)
		//panic(err) //shows stack information
	}
}
