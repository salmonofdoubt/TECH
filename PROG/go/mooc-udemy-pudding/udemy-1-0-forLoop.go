/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
package main

import "fmt"

func forLoop1() {

	fmt.Println("--1--")

	var a [5]int //pre fab

	fmt.Println(a)
	for i := range a {
		a[i] = i
	}
	fmt.Println(a)
}

func forLoop2() {

	fmt.Println("--2--")

	var s []int
	for i := 1; i < 11; i++ { //whatever start number, it will be key 0
		//note that s[i] = i  won't work here, there is no s[i] yet, s[] is void
		//need to append positions first by giving them some value
		s = append(s, 0)
	}

	for k, v := range s { // for k, v ... supressing v
		fmt.Printf("\nvalue at [%d] = %v:\n", k, v)
		fmt.Println("in other words:", k, v)
	}

	for i := 0; i < 10; i++ {
		s[i] = i + 10
	}

	for v := range s { // for k, v ... supressing v
		fmt.Println(s[v])
	}

	for _, v := range s { // for k, v ... supressing v
		fmt.Println(v)
	}
}

func forLoop3() {
	fmt.Println("--3--")
	for i := 0; i < 3; i++ {
		//executes its first step, nothing really do do..
		for j := 0; j < 3; j++ {
			//goes right into next inner loop, executes its first step, nothing really to do..
			for k := 0; k < 3; k++ {
				//goes into yet another loop, executes its first step, second, third step.
				//then back to previous loop
				//executes previous loop's second step, ah nothing to do there, go in here..repeat..
				fmt.Println(i, "-", j, "-", k)
			}
		}
	}
}

func forLoop4() {
	fmt.Println("--4--")
	i := 0
	for i < 10 {
		fmt.Println(i)
		i++
	}
	i = 0 //reset i, otherwise its value is '9'
	for {
		fmt.Println(i)
		if i >= 5 {
			break
		}
		i++
	}
}

func forLoop5() {
	fmt.Println("--5--")
	for i := 0; ; i++ {
		if i%2 == 0 {
			continue
		}
		fmt.Println(i)
		if i >= 50 {
			break
		}
	}
}

func main() {
	forLoop1()
	forLoop2()
	forLoop3()
	forLoop4()
	forLoop5()
}
