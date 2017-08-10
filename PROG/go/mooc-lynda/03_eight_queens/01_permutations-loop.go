package main

import "fmt"

func main() {
	options := []string{"A", "B", "C"} //N! 3*2*1=6 ABC ACB BAC BCA CAB CBA
	for _, x := range options {        //k, v  k is surpressed. Execute first step, nothing really to do..
		for _, y := range options { //goes right into next inner loop, executes its first step, nothing really to do..
			for _, z := range options {
				//goes into yet another loop, executes its first step, second, third step. AAA AAB AAC
				//then back to previous loop
				//executes previous loop's second step, ah nothing to do there, go in here..ABA ABB ABC..repeat
				fmt.Println(x, y, z)
			}
		}
	}
}
