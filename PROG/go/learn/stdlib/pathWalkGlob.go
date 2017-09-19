// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Standard library:
	path			 : manipulates only linux like OS path seperator
	path/filepath: manipulates any ops path
	flags

3) List all files/directories with name = “*atl15*” under directory: “/home/build/google3/platforms/networking/data/model”

hint: filepath.Glob?
*/

package main

import (
	"fmt"
	"os"
	"path/filepath"
)

var pattern string

func main() {

	mypath := "/home/build/google3/platforms/networking/data/model"

	//see filepath.Match
	pattern = "*atl15*"

	//filepath.Walk takes dir and walk function as arguments
	//starting with that root, it walks tree fwd
	filepath.Walk(mypath, walkFunc)
}

func walkFunc(mypath string, info os.FileInfo, err error) error {
	if !info.IsDir() {
		return nil
	}
	//Glob returns the names of all files matching pattern or nil if there is no matching file
	if i, _ := filepath.Glob(filepath.Join(mypath, pattern)); i != nil {
		for _, v := range i {
			fmt.Println("found:", v)
		}
	}

	return nil
}
