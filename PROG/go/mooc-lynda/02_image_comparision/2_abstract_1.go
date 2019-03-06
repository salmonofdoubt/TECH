package main

import (
	"fmt"
	"image"
	"image/jpeg"
	"log"
	"os"
)

func loadImage(fileName string) image.Image {

	//open file
	f, err := os.Open(fileName)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	//Decode the jpeg
	decoded, err := jpeg.Decode(f)
	if err != nil {
		log.Fatal(err)
	}
	return decoded
}

func main() {

	img := loadImage("DATA/78771293.jpg")

	r, g, b, a := img.At(0, 0).RGBA()
	fmt.Printf("%T %T %T %T \n", r, g, b, a)
	fmt.Printf("%v %v %v %v \n", r, g, b, a)
}
