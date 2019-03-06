// author: abaumann@google.com
// From go/gonotes Jan 17 2017

/*
Program which accepts an integer, a string, a bool each as flag. It also accepts a non-flag argument.

$ go run PROG/go/g3train/StdLibFlags1.go -word ho -num 123 tailstuff
Parsed flags, if any. Otherwise print defaults:
word:   ho
num:    123
fork:   false
strVar: bar string
unspeccified: [tailstuff] []string
*/

package main

import (
	"flag" //implements command-line flag parsing
	"fmt"
	"reflect"
)

func main() {

	//Setting some defaults
	wordPtr := flag.String("word", "foo", "a string")
	numPtr := flag.Int("num", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")

	var strVar string
	//Option to use existing var as flag: pointer to the flag declaration function.
	//https://golang.org/pkg/flag/
	flag.StringVar(&strVar, "strVar", "bar", "a string var")

	// parse all cmd-line flags given into main
	flag.Parse()

	// Lets see the parsed options and flags provided, dereferencing where needed.
	fmt.Println("Parsed flags, if any. Otherwise print defaults:")
	fmt.Println("word:  ", *wordPtr)
	fmt.Println("num:   ", *numPtr)
	fmt.Println("fork:  ", *boolPtr)
	fmt.Println("strVar:", strVar, reflect.TypeOf(strVar))
	fmt.Println("unspecified:  ", flag.Args(), reflect.TypeOf(flag.Args()))
}
