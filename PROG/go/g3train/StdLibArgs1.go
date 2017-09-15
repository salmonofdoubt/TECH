// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Exercises
1) Write a program which accepts an integer and string as flags. It also accept non-flag arguments.
The program should display which flags were passed with its values as well as non-flag arguments.

In standard lib, Go provides a `flag` package supporting basic flags

file usage
	go run <file>.go -word="something" -num=3 -fork=true
	or after building
	./<file_no_extention>  -word="something" -num=3 -fork=true
*/

package main

import "flag"
import "fmt"

func main() {

	//Setting defaults
	wordPtr := flag.String("word", "foo", "a string")
	numPtr := flag.Int("num", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")

	//An option to use existing var declared elsewhere in the program.
	//Pass a pointer to the flag declaration function.
	var strvar string
	flag.StringVar(&strvar, "strvar", "bar", "a string var")

	// parse all cmd-line flags into main
	flag.Parse()

	// Dump out the parsed options and any trailing positional arguments.
	// We need to dereference the pointers using '*' to get actual option values.
	fmt.Println("declared defaul flags:")
	fmt.Println("word:  ", *wordPtr)
	fmt.Println("num:   ", *numPtr)
	fmt.Println("fork:  ", *boolPtr)
	fmt.Println("strvar:", strvar)
	fmt.Println("tail:  ", flag.Args(), "...if there was cli input")
}
