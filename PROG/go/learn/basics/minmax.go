package main

import "fmt"

func minmax(xs []int) (int, int) {
	min := xs[0]
	max := xs[0]
	for i := 0; i <= len(xs)-1; i++ {
		if xs[i] <= min {
			min = xs[i]
		} else if xs[i] >= max {
			max = xs[i]
		}
	}
	return min, max
}

func main() {
	arr := []int{2, 200, 2000, 3, 2007, 0}
	//min and max being the two returns from minmax()
	//no need to call minmax() again, as this is done when vars are being evaluated
	min, max := minmax(arr)
	fmt.Println("min:", min, "max:", max)
}
