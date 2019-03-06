package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var s string

	//reads one word (no spaces)
	fmt.Scan(&s)
	fmt.Println(s)

	//read string line incl spaces
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n') //ReadString needs something to conclude call
	fmt.Println(str)
}
