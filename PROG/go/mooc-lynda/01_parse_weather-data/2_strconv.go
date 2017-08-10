package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"strconv"
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
	fmt.Println(rdr.TrimLeadingSpace)
	rdr.TrimLeadingSpace = true
	fmt.Println(rdr.TrimLeadingSpace)

	rows, err := rdr.ReadAll() // remember the return here is [][]string
	// so rows is of type [][]string

	if err != nil {
		panic(err)
	}

	//convert data we are interested in to float, so to make calculations on them
	//air temp at, barometric pressure bm, wind speed ws
	for i, row := range rows {
		if i != 0 && i < 10 {
			at, _ := strconv.ParseFloat(row[1], 64)
			bm, _ := strconv.ParseFloat(row[2], 64)
			ws, _ := strconv.ParseFloat(row[7], 64)

			fmt.Printf("%T %T %T\n", at, bm, ws)
			fmt.Println(at, bm, ws) // they are floats now
			break
		}
	}
}
