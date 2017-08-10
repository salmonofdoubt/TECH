package main

import (
	"encoding/csv"
	"fmt"
	"os"
)

func main() {
	//Lets open a file. os package helps us

	path := "DATA/EDD2015.txt"
	f, err := os.Open(path)
	if err != nil {
		panic(err)
	}
	fmt.Printf(" Type of f: %f Value of f: %v", f, f)

	//since f has been made type *File (stdlib os), it has methods.
	//so we don't call it like that: os.Close(f), nonono..
	//we are using method ".Close()". See?
	defer f.Close()

	//lets create a reader first
	rdr := csv.NewReader(f) //io.Reader is an inteface, and f implements this interfaces
	rdr.Comma = '\t'
	fmt.Println("\n rdr:", rdr)

	//So what can a *Reader from csv package actually do?
	//https://golang.org/pkg/encoding/csv/
	//Lets read file by row maybe? Type csv.*Reader has a ReadAll method.
	rows, err := rdr.ReadAll() //>>Fields [dim1] vvRecords [dim2]
	if err != nil {
		panic(err)
	}
	fmt.Println("len row:", len(rows))

	for i, row := range rows {
		fmt.Println(i, row)
	}
	//rather than dumping the whole file
	//fmt.Println(rows)

	fmt.Println("len row:", len(rows))

	for i, row := range rows {
		if i == 0 {
			fmt.Println(i, row[0])
			continue
		}
		if i == 10000 {
			fmt.Println(i, row)
		}
	}
}
