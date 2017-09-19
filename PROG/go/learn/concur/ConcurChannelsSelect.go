/*

//if there is data on ay of the channels:
select  // just like switch
case a:= <- ch1:
//
case b:= <- ch2:
//
case c:= <- ch3:
//
default:
//

*/

package main

import (
	"fmt"
	"strings"
)

func writeToChannel(s string, input chan string) {

	newStr := strings.Split(s, " ")
	//put words onto channel
	for i := range newStr {
		input <- newStr[i]
	}
	close(input)
}

func upperFunc(input, output chan string) {
	for s := range input {
		s = strings.ToUpper(s)
		output <- s
	}
	close(output)
}

func lowerFunc(input, output chan string) {
	for s := range input {
		s = strings.ToLower(s)
		output <- s
	}
	close(output)
}
func main() {

	//declare channels
	ch1 := make(chan string)
	ch2 := make(chan string)
	ch3 := make(chan string)
	done := make(chan string)

	//goroutines
	go writeToChannel("Hello World", ch1)
	go upperFunc(ch1, ch2)
	go lowerFunc(ch1, ch3)

	/*
		//basically for as long as the channels are open:
			for item := range ch2 {
				fmt.Println("ch2:", item)
			}
			for item := range ch3 {
				fmt.Println("ch3:", item)
			}
	*/
	for {
		select { // just like switch
		case msg1 := <-ch2:
			fmt.Println(msg1)
		case msg2 := <-ch3:
			fmt.Println(msg2)
		case msg3 := <-done:
			fmt.Println(msg3)
		}
	}

	fmt.Println("---</main>---")
}
