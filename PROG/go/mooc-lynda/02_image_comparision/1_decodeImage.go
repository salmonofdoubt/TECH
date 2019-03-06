package main

import (
	"fmt"
	"image/jpeg"
	"log"
	"os"
)

func main() {

	file := "DATA/78771293.jpg"

	//open file
	f, err := os.Open(file)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	//Decode the jpeg
	decoded, err := jpeg.Decode(f)
	if err != nil {
		log.Fatal(err)
	}
	r, g, b, a := decoded.At(0, 0).RGBA()
	fmt.Printf("%T %T %T %T \n", r, g, b, a)
	fmt.Printf("%v %v %v %v \n", r, g, b, a)
}
