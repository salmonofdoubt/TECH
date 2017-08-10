package main

import "fmt"
import "unittesting-packages/testing3/math"

func main() {
	xs := []float64{}
	avg := math.Average(xs)
	fmt.Println(avg)
}
