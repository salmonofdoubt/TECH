package main

import (
	"encoding/csv"
	"fmt"
	"os"
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

	fmt.Println("air temp mean  :", means(rows, 1))
	fmt.Println("barometric mean:", means(rows, 2))
	fmt.Println("wind speed mean:", means(rows, 7))

	end := time.Now()
	delta := end.Sub(start)
	fmt.Println(delta)
}

//calculate means by abstracting it into a func
func means(rows [][]string, pos int) float64 {
	var sum float64
	for i, row := range rows {
		if i != 0 {
			val, _ := strconv.ParseFloat(row[pos], 64)
			sum += val
		}
	}
	return sum / float64(len(rows)-1)
}
