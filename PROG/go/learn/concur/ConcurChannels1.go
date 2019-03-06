/*
author: abaumann@google.com
From go/gonotes 17/01/2017, HWK 24/01/2017

Concurrency (Part II) - Single element written and read, unbuffered

Channels to either synchroneous or asynchroneous process go routines
main() may otherwise runs ahead and exit after spinning off go routines
Whole idea is not to have returns from go routines.

Bufferend channels:  fixed lenght buffer: access to it is non-blocking until full,
                     some routine at last must then drain it
Unbuffered channels: in fact zero-lenght buffer that always blocks unless
                     some routine is ready to drain an item

HWK:
Create two go routines, one write Hello, World to channel, second reads from this channel,
makes them upper case and put this in another channel. Main then reads that upper case
*/

package main

import (
	"fmt"
	"strings"
)

func writeToChannel(input chan string) {
	//put content on channel that was passed in
	input <- "Hello World"
}

func readFromChannel(input, output chan string) {
	//dump string from channel c1 on a var
	s := <-input
	//convert string
	s = strings.ToUpper(s)
	//put new content on channel c2
	output <- s
}

func main() {
	//declare channels
	c1 := make(chan string)
	c2 := make(chan string)

	//goroutine that writes something to channel c1
	go writeToChannel(c1)
	//goroutine that reads from c1, modifies, and writes to c2
	go readFromChannel(c1, c2)

	//finally dump channel c2
	fmt.Println("Read result from channel c2:", <-c2)

	//exit gracefully not necessary
	//time.Sleep(1 * time.Second)

	fmt.Println("---</main>---")
}
