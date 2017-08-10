// author: abaumann@google.com
// From go/gonotes, this program addresses questions 1-4
// The proof is in the pudding...

package main

import (
	"errors"
	"fmt"
)

var ZeroLengthError = "Zero length input"

func main() {

	//1 Write function that finds min and max in slice of integers. Return error if the slice is empty.
	arr1 := []int{2, -3, 4, 17} //-3, 17
	arr2 := []int{}             //Error
	fmt.Println("\n---1---")
	fmt.Println(minMax(arr1))
	fmt.Println(minMax(arr2))

	//2 Write function that adds all integers passed as argument. Return error if no integer was passed.
	fmt.Println("\n---2---")
	fmt.Println(add(1, 2, 3, 4))
	s := []int{1, 2, 3, 4}
	fmt.Println(add(s...)) //"..." calls sequentially
	fmt.Println(add())

	//3 Write function that takes an integer and halves it. Return true if it was even, false if it was odd number.
	//Returns an error if the integer is 0.
	//For example half(1) should return (0, false) and half(2) should return (1, true). (HWK)
	fmt.Println("\n---3---")
	for i := -4; i <= 4; i++ { //include some negative numbers
		fmt.Println(halfInt(i))
	}

	//4	Write function with one variadic parameter that finds the greatest value in a list of integers.
	//Return an error if the list is empty. (HWK)
	fmt.Println("\n---4---")
	list1 := []int{2, 6, 9, 4, 5, 6}
	list2 := []int{17, 43, 83, 9, -200, 2, 0, 8}
	list3 := []int{}

	fmt.Println(greatest(list1...)) //9 nil
	fmt.Println(greatest(list2...)) //83 nil
	fmt.Println(greatest(list3...)) //-1 Error
}

//1
func minMax(a []int) (int, int, error) {
	var min, max int
	if len(a) == 0 {
		return -1, -1, errors.New(ZeroLengthError)
	}
	min = a[0]
	max = a[0]
	for i := range a {
		switch {
		case a[i] < min:
			min = a[i]
		case a[i] > max:
			max = a[i]
		}
	}
	return min, max, nil
}

//2
func add(a ...int) (int, error) {
	var res int
	if len(a) == 0 {
		return -1, errors.New(ZeroLengthError)
	}
	for i := range a {
		res = res + a[i]
	}
	return res, nil
}

//3
func halfInt(itg int) (float64, bool, error) {
	var res float64
	switch {
	case itg == 0:
		return -1, false, errors.New(ZeroLengthError)
	case itg == 1:
		res = 1
		return res, false, nil
	case itg%2 == 0:
		return float64(itg) / 2, true, nil
	default:
		return float64(itg) / 2, false, nil
	}
}

//4
func greatest(list ...int) (int, error) {
	if len(list) == 0 {
		return -1, errors.New(ZeroLengthError)
	}
	max := list[0]
	for i := range list {
		if list[i] > max {
			max = list[i]
		}
	}
	return max, nil
}
