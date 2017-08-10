// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Standard library:
	path			 : manipulates only linux like OS path seperator
	path/filepath: manipulates any ops path
	flags

5) Implement “myfind”, similar to linux command find, to find all the files with a given filename in a given directory.
Usage: myfind -name <filename> <directory>
walk through the dir and find that files
*/

package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
)

//args are usually global vars, here being passed to or just used in walkFunc()
var (
	root = flag.String("root", "/usr/local/google/home/abaumann/workspace/ra", "a path")
	file = flag.String("file", "myfile.txt", "a filename")
)

func main() {

	flag.Parse()
	fmt.Println("Starting at:", *root, "find:", *file, "\n")

	//filepath.Walk takes dir and walk function as arguments
	//starting with that root, it walks tree fwd
	filepath.Walk(*root, walkFunc)
}

// walk func which filepath.Walk calls over and over
func walkFunc(current string, info os.FileInfo, err error) error {
	fileName := filepath.Base(current)
	if fileName == *file {
		fmt.Println("Found :", *file, " in:", filepath.Dir(current))
	}
	return nil
}

/* RESULTS
$ go run g3TrainStdLibPathWalkMyfind.go
Starting at: /usr/local/google/home/abaumann/workspace/ra find: myfile.txt

Found: myfile.txt here: /usr/local/google/home/abaumann/workspace/ra/dir1
Found: myfile.txt here: /usr/local/google/home/abaumann/workspace/ra
*/
