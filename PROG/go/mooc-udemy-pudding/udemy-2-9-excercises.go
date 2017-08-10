////////////////////////////////////////////////////////////////////////////////
//////////////////// The proof is in the pudding ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

package main

import "fmt"

func main() {

	//task0: get a return with half and eveness...
	fmt.Println(takeint(17))

	//another way
	half, even := takeint(17) // half and even are the 2 returns
	fmt.Println(half, even)
	fmt.Println("///// task0 complete //////")

	//task1: written as function expression, remains within main
	funcexp := func(x int) (int, bool) { return x / 2, x%2 == 0 }
	fmt.Println(funcexp(17))
	fmt.Println("\n///// task1 complete ///////")

	//task2: variadic func that finds largest number in list
	fmt.Println(largest(18, 13, 17, 19))
	fmt.Println("\n///// task2 complete //////")

	//task3: value of "(true && false)||(false && true) || !(false && false)"
	fmt.Println((true && false))
	//				false				false
	//							false						true
	//											true
	fmt.Println("\n///// task3 complete //////")

	//task4: another variadic func exercise
	foo(1)
	foo(1, 2)
	foo(1, 2, 3)
	aSlice := []int{1, 2, 3, 4}
	foo(aSlice...) //pass this as a variadic type (if type is the right word)
	foo()

	//task5: projecteuler.net

}

func takeint(x int) (int, bool) { // two returns but obviously only ever one return statement
	return x / 2, x%2 == 0
}

func largest(input ...int) int {
	fmt.Printf("%T \n", input) //just curious what's passed here
	bigger := 0
	for _, v := range input {
		if v > bigger {
			bigger = v
		}
	}
	return bigger
}

func foo(numbers ...int) {
	fmt.Printf("%T  ", numbers)
	fmt.Println(numbers)

}
