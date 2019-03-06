package main

import (
	"fmt"
	"io/ioutil"
	"os"

	"log"
)

func main() {
	//Lets open an image
	f, err := os.Open("DATA/78771293.jpg")
	if err != nil {
		log.Fatal(err)
	}

	//since f has been made type *File (stdlib os), it has methods.
	//so we don't call it like that: os.Close(f), nonono..we are using method ".Close()". See?
	defer f.Close()

	//Readall() takes a Reader interface, that has read method, and a *File implements that
	//polymorphism
	bs, _ := ioutil.ReadAll(f)
	fmt.Println(bs)
	fmt.Printf(" Type of f: %f Value of f: %v", f, f)
	fmt.Println(f)
}
