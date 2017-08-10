package main

import (
	"fmt"
	"image"
	"image/jpeg"
	"log"
	"os"
	"path/filepath"
)

func collectDecodedFiles(myPath string) []image.Image {

	var images []image.Image

	//We want to read all files though
	//func Walk(root string, walkFn WalkFunc) error passing in a func thats a callback, recursion
	filepath.Walk(myPath, func(path string, info os.FileInfo, err error) error {
		//here we use path and info
		if info.IsDir() {
			return nil
		}
		fmt.Println("In file path:", path)

		img := loadImage(path)
		images = append(images, img)
		return nil
	})
	return images
}

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
	myPath := "DATA/"
	images := collectDecodedFiles(myPath)

	for i, v := range images {
		r, g, b, a := v.At(0, 0).RGBA()
		fmt.Println(i)
		fmt.Printf("Color Types %T %T %T %T \n", r, g, b, a)
		fmt.Printf("Color Values %v %v %v %v \n", r, g, b, a)
	}
}
