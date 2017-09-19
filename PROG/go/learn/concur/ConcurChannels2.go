/*
author: abaumann@google.com
From go/gonotes 17/01/2017, HWK 24/01/2017

Concurrency (Part II) - Several items written and read, unbuffered

Channels to either synchroneous or asynchroneous process go routines
main() may otherwise runs ahead and exit after spinning off go routines
Whole idea is not to have returns from go routines.

Bufferend channels:  fixed lenght buffer: access to it is non-blocking until full,
                     some routine at last must then drain it
Unbuffered channels: in fact zero-lenght buffer that always blocks unless
                     some routine is ready to drain an item

HWK:
Create two go routines, one writes string from arg to channel, second reads from this channel,
makes them upper case and put this in another channel. Main then reads that upper case
*/

package main

import (
	"flag"
	"fmt"
	"strings"
)

func writeToChannel(s string, input chan string) {

	//split string into words
	newStr := strings.Split(s, " ")

	//put words onto channel
	for i := range newStr {
		input <- newStr[i]
	}

	//close once loop is finished
	close(input)
}

func upperFunc(input, output chan string) {

	//for as long as input is open, loop and upper each word and put on second channel
	for s := range input {
		s = strings.ToUpper(s)
		output <- s
	}
	close(output)
}

func main() {

	//get string as an arg
	argInput := flag.String("string", "foo", "a string")
	flag.Parse()
	fmt.Println("Received:", *argInput)

	//declare channels
	c1 := make(chan string)
	c2 := make(chan string)

	//goroutines
	go writeToChannel(*argInput, c1)
	go upperFunc(c1, c2)

	//basically as long as this channel is open:
	for item := range c2 {
		fmt.Println("main reads channel:", item)
	}

	fmt.Println("---</main>---")
}
