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

	wordPtr := flag.String("word", "foo", "a string")
	numbPtr := flag.Int("num", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")

	// It's also possible to declare an option that uses an
	// existing var declared elsewhere in the program.
	// Pass a pointer to the flag declaration function.
	var strvar string
	flag.StringVar(&strvar, "strvar", "bar", "a string var")

	// parse all cmd-line flags into main
	flag.Parse()

	// Here we'll just dump out the parsed options and
	// any trailing positional arguments. Note that we
	// need to dereference the pointers with e.g. `*wordPtr`
	// to get the actual option values.
	fmt.Println("word:", *wordPtr)
	fmt.Println("numb:", *numbPtr)
	fmt.Println("fork:", *boolPtr)
	fmt.Println("strvar:", strvar)
	fmt.Println("tail:", flag.Args())
}
