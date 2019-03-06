package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {

	newFile, err := os.Create("sample.txt")
	if err != nil {
		log.Fatal(err)
	}

	newFile.WriteString("This is new input.")
	newFile.Close()

	reader, err := ioutil.ReadFile("sample.txt")

	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%T %v\n", reader, reader)
	fmt.Println(string(reader))

}
