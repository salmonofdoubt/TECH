package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
)

func main() {

	dir := "test-files/"
	files, _ := ioutil.ReadDir(dir)

	for i, f := range files {
		fmt.Println(f.Name())
		oldfile := (dir + f.Name())
		newfile := (dir + strconv.Itoa(i) + ".jpg")
		fmt.Println(oldfile, "to", newfile, "\n")

		err := os.Rename(oldfile, newfile)
		if err != nil {
			fmt.Println(err)
			return
		}
	}
}
