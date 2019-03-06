// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Standard library:
	path			: manipulates only linux like OS path seperator
	path/filepath	: manipulates any ops path

2) Given the path “/google/data/ro/projects/netops/gdrain.sh”
- Check whether it is an absolute path
- Display the name of file
- Display the extension of the file
- Display the directory
*/

package main

import (
	"fmt"
	"path"
)

func main() {

	myPath := "/google/data/ro/projects/netops/gdrain.sh"

	fmt.Println("Abs filepath:", path.IsAbs(myPath))
	fmt.Println("Name:        ", path.Base(myPath))
	fmt.Println("Ext:         ", path.Ext(myPath))
	fmt.Println("Dir:         ", path.Dir(myPath))
}
