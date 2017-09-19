package main

import "fmt"

func sumArray(xs []int) int {
	var total int
	for _, v := range xs {
		total += v
	}
	return total
}

func reverseArr1(xs []int) []int {
	var out []int
	for i := len(xs) - 1; i >= 0; i-- {
		out = append(out, xs[i])
	}
	//fmt.Println(out)
	return out
}

func reverseArr2(input []int) []int { //recursion has poor perf
	if len(input) == 0 {
		return input
	}
	return append(reverseArr2(input[1:]), input[0])
}

func findDups(xs []int) []int { //receives int array xs, and returns an int array
	var out []int //create aux array of type int
	a := make(map[int]int)

	for _, v := range xs {
		_, ok := a[v]
		if !ok {
			out = append(out, v)
			a[v] = 1
		}
	}
	return out
}

func main() {
	intarr := []int{11, 12, 13, 13, 13, 14}
	fmt.Println("\nsumArray.......:", intarr, sumArray(intarr))
	fmt.Println("\nreverseArr1...:", intarr, reverseArr1(intarr))
	fmt.Println("\nreverseArr2....:", intarr, reverseArr2(intarr))
	fmt.Println("\nfindDups.......:", intarr, findDups(intarr))
}
