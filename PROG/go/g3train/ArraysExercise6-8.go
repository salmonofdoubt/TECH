//
// https://docs.google.com/document/d/1xhnvHtkGLJX2kWYbj_k59WlmfPP55L1GAap5G87ffvo/edit#heading=h.iz6v4wlhlnkk
//
//

package main

import (
	"fmt"
	"sort"
)

func main() {

	//6
	s61 := []int{1, 2, 3, 4, 5, 6}
	s62 := []int{7, 8, 9}
	fmt.Println("\n//6")
	sixMisc(s61, s62)

	//7
	var m = map[int]string{
		1: "Mon",
		2: "Tue",
		3: "Wed",
		4: "Thu",
		5: "Fri",
		6: "Sat",
		7: "Sun",
	}
	fmt.Println("\n//7")
	fmt.Println(mapWeek(m))

	//8
	s8 := []int{1, 1, 3, 4, 1, 3, 5, 6, 3}
	fmt.Println("\n//8")
	fmt.Println(dups(s8))

}

//6
func sixMisc(a, b []int) {
	//Append slice b to slice a. Print a
	a = append(a, b...)
	fmt.Println("a:", a)

	//Copy slice a to a new slice c. Print c
	c := make([]int, len(a))
	copy(c, a)
	fmt.Println("c:", c)

	//Delete item at index 5 in slice a. Print a
	a = append(a[:5], a[5+1:]...)
	fmt.Println("a less 5th:", a)

	//Cut from index 2 till 5 out of slice a. Print a
	a = append(a[:2], a[6:]...)
	fmt.Println("a less 2..5th:", a)

	//Extend slice a with a new empty slice of length 5. Print a
	e := make([]int, 5)
	a = append(a, e...)
	fmt.Println("a plus 5 empty:", a)

	//Insert item 10 at index 5 in a. Print a.
	a = append(a[:5], append([]int{10}, a[5:]...)...)

	fmt.Println("a add 10 at 5:", a)

	//Insert a new slice of length 3 at index 4 in a. Print a.
	a = append(a[:4], append(make([]int, 3), a[4:]...)...)
	fmt.Println("a new slice of 3 at index 4:", a)

	//Insert a slice b at index 4 in a
	a = append(a[:4], append(b, a[4:]...)...)
	fmt.Println("a insert slice b at index 4:", a, "( b = :", b, ")")

	//Pop highest element from stack a. Print a and the element.
	a = a[:len(a)-1]
	fmt.Println("a pop highest element:", a)

	//Push an element 20 on a stack a. Print a.
	a = append(a, 20)
	fmt.Println("a push 20 on stack:", a)

}

//7
func mapWeek(m map[int]string) ([]string, []string) {
	//fmt.Println("m:", m, "len", len(m))
	var order []int
	var fwd, bwd []string

	for k, v := range m {
		var tue bool
		if v == "Tue" {
			tue = true
			fmt.Println("Tue?", tue)
		}
		if v == "Holy" {
			fmt.Println("holiday")
		}
		order = append(order, k)
	}
	sort.Ints(order) //inplace operation

	for i := 0; i < len(order)+1; i++ {
		fwd = append(fwd, m[i])
	}
	for i := len(order) + 1; i >= 0; i-- {
		bwd = append(bwd, m[i])
	}
	return fwd, bwd
}

//8
//Remove duplicates from slice. how many times each number was in the slice.
func dups(d []int) ([]int, map[int]int) {

	//occurred := map[int]bool{} //map flips to true on occurence
	counter := map[int]int{} //map that records occurences [int:occurance]
	result := []int{}

	for _, v := range d {
		if _, ok := counter[v]; !ok {
			result = append(result, v)
		}
		counter[v] += 1
	}
	return result, counter
}
