package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan bool)             //a channel that takes booleans
	go waitAndSee(c, "wait and see") //so that runs as go routine now, but c has no trigger yet
	fmt.Println("Yes I will ")       // meanwhile we print something

	time.Sleep(3 * time.Second)
	c <- true //now let's trigger the channel, that will make waitAndSee() to print
	<-c       // main now blocks until it receives something on c
	fmt.Println("now I got it")

	time.Sleep(6 * time.Second)

}

func waitAndSee(c chan bool, s string) {
	if b := <-c; b { //so if b is true
		fmt.Println(s)
	}
	time.Sleep(3 * time.Second)
	c <- true //lets put true on the channel so main see it and
}
