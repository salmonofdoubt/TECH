package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	yourName, _ := reader.ReadString('\n')
	fmt.Println(yourName)

	var yourAge int
	fmt.Scan(&yourAge)

	if yourAge >= 18 {
		fmt.Println("You may drive")
	} else if yourAge > 16 {
		fmt.Println("You may have fun")
	} else {
		fmt.Println("We are not sure")
	}

	switch yourAge {
	case 18:
		fmt.Println("You may drive")
	case 16:
		fmt.Println("You may have fun")
	default:
		fmt.Println("We are not sure")
	}
}
