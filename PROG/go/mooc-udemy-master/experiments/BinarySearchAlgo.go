// Comment main ...
package main

import "fmt"

// find item in list
// guess at middle, etc..

func main() {
	arr := []int{0, 2, 4, 6, 8, 9}
	target := 1
	low := 0
	high := len(arr) - 1
	fmt.Println("Parameters:", arr, target, high, low)

	recursive := fmt.Sprintf("recBinSearch found target %v at index %v.", target, recBinSearch(arr, target, low, high))
	fmt.Println(recursive)

	iter := fmt.Sprintf("iterBinSearch found target %v at index %v.", target, iterBinSearch(arr, target, low, high))
	fmt.Println(iter)

}

func recBinSearch(array []int, target, lowIndex, highIndex int) int {
	if highIndex < lowIndex {
		return -1 //condition when to end the recursion
	}
	mid := int((highIndex + lowIndex) / 2) // cast into int
	fmt.Println("recBinSearch: middle at pos:", mid)
	if array[mid] > target { //check if target is more or less the target
		return recBinSearch(array, target, lowIndex, mid)
	} else if array[mid] < target { //check if target is more or less the target
		return recBinSearch(array, target, mid+1, highIndex)
	} else {
		return mid // reached position
	}
}

func iterBinSearch(array []int, target, lowIndex, highIndex int) int {
	low := lowIndex
	high := highIndex
	var mid int
	for low <= high {
		mid = int((low + high) / 2)
		fmt.Println("iterBinSearch: middle at pos:", mid)
		if array[mid] > target {
			high = mid
		} else if array[mid] < target {
			low = mid + 1
		} else {
			return mid // reached position
		}
	}
	return -1
}
