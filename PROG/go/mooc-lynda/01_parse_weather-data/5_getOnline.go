package main

import (
	"encoding/csv"
	"fmt"
	"log"
	"net/http"
	"sort"
	"strconv"
	"time"
)

func main() {

	//from http package, run Get()
	//which gives us a *Response type
	res, err := http.Get("https://raw.githubusercontent.com/GoesToEleven/lynda/master/cc/01_parse_weather-data/Environmental_Data_Deep_Moor_2015.txt")
	if err != nil {
		log.Fatal(err)
	}
	rdr := csv.NewReader(res.Body) //so we want the Body
	rdr.Comma = '\t'
	rdr.TrimLeadingSpace = true
	defer res.Body.Close()
	rows, err := rdr.ReadAll() //stick it into rows (which will be a [][]string)
	if err != nil {
		panic(err)
	}

	start := time.Now()

	fmt.Println("air temp\tmeans:", means(rows, 1), "\tmedian", median(rows, 1))
	fmt.Println("barometric\tmeans:", means(rows, 2), "\tmedian", median(rows, 2))
	fmt.Println("wind speed\tmeans:", means(rows, 7), "\tmedian", median(rows, 7))
	end := time.Now()
	delta := end.Sub(start)
	fmt.Println(delta)
}

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

	if len(toBeSorted)%2 != 0 {
		//len is odd, returns the value we find at that position
		return toBeSorted[len(toBeSorted)/2]
	}
	//len is even
	higher := toBeSorted[len(toBeSorted)/2] //it's a value at that position
	lower := toBeSorted[len(toBeSorted)/2-1]
	return (higher + lower) / 2
}
