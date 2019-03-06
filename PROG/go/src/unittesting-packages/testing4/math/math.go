package math

import "fmt"

func Average(xs []float64) float64 { //takes slice of float, returns float
	total := float64(0)
	fmt.Println(total)
	for _, x := range xs {
		total += x
	}
	return total / float64(len(xs))
}
