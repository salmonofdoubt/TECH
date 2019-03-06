package main

import "fmt"

func main() {
	c := make(chan int, 2)

	c <- 1
	c <- 2

	fmt.Println(<-c) //takes first element off the channel so 2 remains on channel
	c <- 1           // put something else on channel
	fmt.Println(<-c) // takes first element off the channel
	fmt.Println(<-c) // second off
	//fmt.Println(<-c) //deadlock, nothing to take from the channel

}
