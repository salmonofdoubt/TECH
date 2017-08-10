// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Standard library:
	path			 : manipulates only linux like OS path seperator
	path/filepath: manipulates any ops path
	flags

4a) Using the directory “/home/build/google3/platforms/networking/data/model”:
Count the number of files per file extMapension. Print the result.

4b) Find duplicate filenames (not consider the directory as part of the filename).
Print the result.

hint: use global map counters?
*/

package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
)

//global maps, initialized as empty with trailing {}
var extMap = map[string]int{}
var fileMap = map[string]int{}

func main() {

	root := flag.String("root", "/usr/local/google/home/abaumann/workspace/ra", "a path")
	flag.Parse()
	//root := "/home/build/google3/platforms/networking/data/model"

	//filepath.Walk takes dir and walk function as arguments
	//starting with that root, it walks tree fwd
	filepath.Walk(*root, walkFunc)

	//print extMap results
	fmt.Println("completed extMap:\n", extMap)

	//print fileMap results
	fmt.Println("dup fileNames:")
	for k, v := range fileMap {
		if fileMap[k] > 1 {
			fmt.Println(k, v)
		}
	}
}

// implementing func instance which filepath.Walk calls over and over
func walkFunc(root string, info os.FileInfo, err error) error {

	//some local vars for readability
	ext := filepath.Ext(root)
	fileName := filepath.Base(root)
	//
	extMap[ext]++
	fileMap[fileName]++

	return nil
}

/* Results
[1] no args : root = "/usr/local/google/home/abaumann/workspace/ra":

completed map:
 extMap: map[.pdf:3 .pds:1 .log:3 :13 .txt:3]
dup fileNames:
 aux.txt 2
*/
