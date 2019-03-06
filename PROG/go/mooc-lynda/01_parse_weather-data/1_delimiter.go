package main

import (
	"encoding/csv"
	"fmt"
	"os"
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

	rows, err := rdr.ReadAll() // remember the return here is [][]string
	// so rows is of type [][]string

	if err != nil {
		panic(err)
	}

	//data we are interested
	//air temp at, barometric pressure bm, wind speed ws
	for i, row := range rows {
		fmt.Println(row)
		if i == 1 {
			fmt.Printf("%T %T %T\n", row[1], row[2], row[7])
			fmt.Println(row[1], row[2], row[7]) // they are numbers but all strings -- eek!
			break
		}
	}
}
