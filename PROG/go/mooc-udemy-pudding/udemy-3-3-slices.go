/////////////////////////////////////
//// The proof is in the pudding ////
/////////////////////////////////////
/////////// slices //////////////////
/////////////////////////////////////

// slice, array: lists
// map         : k,v storage
// channel     : ...
// those 3 are ref types, can use "make", hence dims need to be right

// struct      : data structure

package main

import "fmt"

func main() {

	records := make([][]string, 0) // 2 dims spreadsheet
	fmt.Println("records:", len(records), cap(records), records)

	student1 := make([]string, 4)
	student1[0] = "Foster"
	student1[1] = "Nathan"
	student1[2] = "100.00"
	student1[3] = "74.00"
	fmt.Println("\n", student1)

	for i := range student1 {
		fmt.Println(student1[i])
	}

	records = append(records, student1)
	fmt.Println("records:", len(records), cap(records), records)

	for i, v := range records {
		fmt.Println("i, v:", i, ",", v)
	}

	student2 := make([]string, 4)
	student2[0] = "Gomez"
	student2[1] = "Lisa"
	student2[2] = "92.00"
	student2[3] = "96.00"

	records = append(records, student2)
	fmt.Println("records:", len(records), cap(records), records)

	for i, v := range records {
		fmt.Println("i, v:", i, ",", v)
	}
}
