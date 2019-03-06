//testing the file(s) in this math package
package math

import (
	"testing"
)

type testData struct {
	input  []float64 //function input
	output float64   //function output
}

//instantiation
var tests = []testData{
	{[]float64{1, 2}, 1.5},
	{[]float64{1, 2, 3, 4}, 2.5},
	{[]float64{1, 1, 1, 1}, 1},
	{[]float64{-1, 1}, 0},
	//	{[]float64{}, "NaN"},
}

//testing Average() in math.go, which normally gets called by ../main (myMath.go)
func TestAverage(t *testing.T) {
	for _, pair := range tests {
		v := Average(pair.input)
		if v != pair.output {
			t.Error(
				"For", pair.input,
				"expected", pair.output,
				"got", v,
			)
		}
	}
}
