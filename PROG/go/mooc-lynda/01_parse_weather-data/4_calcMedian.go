package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"sort"
	"strconv"
	"time"
)

func main() {
	f, err := os.Open("DATA/EDD2015.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	//lets create a reader
	rdr := csv.NewReader(f)
	rdr.Comma = '\t'
	rdr.TrimLeadingSpace = true

	rows, err := rdr.ReadAll() // remember the return here is [][]string
	// so rows is of type [][]string

	if err != nil {
		panic(err)
	}

	start := time.Now()

	fmt.Println("air temp median  :", median(rows, 1))
	fmt.Println("barometric median:", median(rows, 2))
	fmt.Println("wind speed median:", median(rows, 7))

	end := time.Now()
	delta := end.Sub(start)
	fmt.Println(delta)
}

//calculate median by abstracting it into a func
func median(rows [][]string, pos int) float64 {
	var toBeSorted []float64
	for i, row := range rows {
		if i != 0 {
			val, _ := strconv.ParseFloat(row[pos], 64)
			toBeSorted = append(toBeSorted, val)
		}
	}
	//in place sort your slice
	sort.Float64s(toBeSorted)

	//now we can look at the middle, median value
	//len is odd
	if len(toBeSorted)%2 != 0 {
		return toBeSorted[len(toBeSorted)/2] //odd, so this is the value we find at that position
	}
	//len is even
	higher := toBeSorted[len(toBeSorted)/2] //it's a value at that position
	lower := toBeSorted[len(toBeSorted)/2-1]
	return (higher + lower) / 2
}
