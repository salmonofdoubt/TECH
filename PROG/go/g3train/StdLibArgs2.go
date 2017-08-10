/*
Exercises
[DONE THIS FILE]
1) Write a program which accepts an integer for Lincard, and string for reason as flags.
   It also accept non-flag arguments.
   The program should display which flags were passed with its values as well as non-flag arguments.

In standars lib, Go provides a `flag` package supporting basic flags

file usage
	go run <file>.go -linecard=3 -reason="pcr/12345"
	or after building
  ./<file_no_extention> -linecard=3 -reason="pcr/12345"
*/

package main

import (
	"flag"
	"fmt"
	"os"
)

func main() {

	lcPtr := flag.Int("linecard", 0, "LC number")
	reasonPtr := flag.String("reason", "", "reason for draining string")

	// Once all flags are declared, call `flag.Parse()` to execute the command-line parsing.
	flag.Parse()

	fmt.Println("linecard:", *lcPtr)
	fmt.Println("reason:", *reasonPtr)
	fmt.Println("others:", flag.Args())

	//understand what was passed
	fmt.Println(len(os.Args), os.Args)

}
