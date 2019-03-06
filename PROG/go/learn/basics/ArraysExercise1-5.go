// https://docs.google.com/document/d/1xhnvHtkGLJX2kWYbj_k59WlmfPP55L1GAap5G87ffvo/edit#heading=h.iz6v4wlhlnkk

package main

import "fmt"

func main() {

	//1
	fmt.Println("//1")
	fmt.Println(loop(15, 2))

	//2
	s2 := []int{5, 3, 8, 1}
	fmt.Println("\n//2")
	fmt.Println(minMax(s2))

	//3
	s3 := []float64{4.5, 5.3, 9.5}
	fmt.Println("\n//3")
	fmt.Println(sumAverage(s3))

	//4
	s41 := []int{1, 2, 3}
	s42 := []int{4, 5}
	fmt.Println("\n//4")
	fmt.Println(addArrays(s41, s42))

	//5
	s5 := []int{1, 2, 3, 4}
	fmt.Println("\n//5")
	fmt.Println(lengthOfString(s5))

}

//1
func loop(upper, plus2 int) ([]int, []int) {
	var s []int
	var sx []int
	for i := 0; i <= upper; i++ {
		s = append(s, i)
		sx = append(sx, i+plus2)
	}
	return s, sx
}

//2
func minMax(xs []int) (int, int) {
	min := xs[0]
	max := xs[0]
	for i := range xs {
		switch {
		case xs[i] < min:
			min = xs[i]
		case xs[i] > max:
			max = xs[i]
		}
	}
	return min, max
}

//3
func sumAverage(s []float64) (float64, float64) {
	var sum, avg float64
	for i := 0; i < len(s); i++ {
		sum = sum + s[i]
	}
	avg = sum / float64(len(s))
	return sum, avg
}

//4
func addArrays(a, b []int) []int {
	a = append(a, b...)
	return a
}

//5
func lengthOfString(s []int) (int, int) {
	return len(s[1:1]), len(s[1:2])
}
