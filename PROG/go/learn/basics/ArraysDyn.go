///////////////////////////////
// The proof is in g3 /////////
///////////////////////////////

/*
Growing a dynamic array is a geometric, constant progression until
the array needs to be resized. O(1)

Resizing means allocating a new contiguous location in memory,
and copying over the old array O(n)

This may not be true for Python and Java where memory may be allocated
in a not contiguous way, costing much more time.
*/

package main

import (
	"fmt"
	"time"
)

func main() {

	var s1 []int

	for i := 0; i < 10; i++ {
		s1 = append(s1, i)
	}

	fmt.Println(len(s1), cap(s1))

	fmt.Println("Adding 5 without resizing")
	start1 := time.Now()
	for i := 10; i < 15; i++ {
		s1 = append(s1, i)
	}
	fmt.Println(len(s1), cap(s1))
	end1 := time.Since(start1)
	fmt.Println(end1)

	fmt.Println("Adding 5 with resizing")
	start2 := time.Now()
	for i := 15; i < 20; i++ {
		s1 = append(s1, i)
	}
	fmt.Println(len(s1), cap(s1))
	end2 := time.Since(start2)
	fmt.Println(end2)

	fmt.Println("Adding another 5 without resizing")
	start3 := time.Now()
	for i := 20; i < 25; i++ {
		s1 = append(s1, i)
	}
	fmt.Println(len(s1), cap(s1))
	end3 := time.Since(start3)
	fmt.Println(end3)

	fmt.Println("Adding another 5 without resizing")
	start4 := time.Now()
	for i := 25; i < 30; i++ {
		s1 = append(s1, i)
	}
	fmt.Println(len(s1), cap(s1))
	end4 := time.Since(start4)
	fmt.Println(end4)

	fmt.Println("Adding another 5 with resizing")
	start5 := time.Now()
	for i := 30; i < 35; i++ {
		s1 = append(s1, i)
	}
	fmt.Println(len(s1), cap(s1))
	end5 := time.Since(start5)
	fmt.Println(end5)

}
