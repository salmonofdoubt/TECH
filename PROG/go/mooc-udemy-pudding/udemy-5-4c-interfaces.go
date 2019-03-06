///////////////////////////////////////
//// The proof is in the pudding //////
///////////////////////////////////////
/////// interface implemented /////////
///////////////////////////////////////
/*
/// We have seen from io package already:
type Reader interface {
	}

type Writer interface {
	}

type Handler interface {
	}

/// Now lets look at the sort package:
type Interface interface { //called Interface, type interface, has a set of methodes
        // Len is the number of elements in the collection.
        Len() int
        // Less reports whether the element with
        // index i should sort before the element with index j.
        Less(i, j int) bool
        // Swap swaps the elements with indexes i and j.
        Swap(i, j int)
}

Exercise:
Use https://godoc.org/sort to sort the following
(1)
type people []string
studyGroup := people{"Zeno", "John", "Al", "Jenny"}
//slice of string, we have a type people

(2)
s := []string{"Zeno", "John", "Al", "Jenny"}

(3)
n := []int{7,4,8,2,9,19,12,32,2}

sort above in ***reverse*** order
*/

package main

import (
	"fmt"
	"sort"
)

/* see "func Sort": <<< func Sort(data Interface) >>>
To implemet anything that uses Sort, your type (here people) needs concrete
methods which the interface Interface stipulates:
<<< type Interface interface {
        Len() int           //number of elements in the collection
        Less(i, j int) bool //reports if element i should sort before j
        Swap(i, j int)      //swaps elements i and j */

type people []string

func (p people) Len() int           { return len(p) }
func (p people) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p people) Less(i, j int) bool { return p[i] > p[j] }

type myints []int

func (x myints) Len() int           { return len(x) }
func (x myints) Swap(i, j int)      { x[i], x[j] = x[j], x[i] }
func (x myints) Less(i, j int) bool { return x[i] > x[j] }

func main() {
	/*
		/// 1 ////////////////////////////////////////////////////////////////////////
		studyGroup1 := people{"Zeno", "John", "Al", "Jenny"}

		//fwd sort easy enough as it doesn't need implemention of Interface:
		//<<< func Strings (a []string) >>>
		sort.Strings(studyGroup1)
		fmt.Println(studyGroup1)

		//needs all methods implemented that sort.Interface stipulates:
		//"func Sort": <<< func Sort(data Interface) >>>
		sort.Sort(studyGroup1)
		fmt.Println(studyGroup1)
	*/

	/// 2 ////////////////////////////////////////////////////////////////////////
	studyGroup2 := people{"Qeno", "Rohn", "Pal", "Erwin", "Zeus"}
	sort.Sort(studyGroup2)
	fmt.Println("studyGroup2:", studyGroup2)

	/// Or make var a StringSlice, which implements, among others, the 3 methods
	/// Interface needs. It won't use "people" type, but "StringSlice".
	/// Hence it's not reversed -- haha.
	studyGroup3 := []string{"Qeno", "Rohn", "Pal", "Erwin", "Zeus"}
	sort.StringSlice(studyGroup3).Sort()
	fmt.Println("studyGroup3 (1):", studyGroup3)

	/// Alternatively, use the sort.Reverse that returns Interface, not using
	/// our type "people" with its implemented methods.
	/// Sort now takes an Interface (backtrace, if it isn't obvious)
	sort.Sort(sort.Reverse(sort.StringSlice(studyGroup3)))
	fmt.Println("studyGroup3 (2):", studyGroup3)

	/// 3 ////////////////////////////////////////////////////////////////////////
	/// using own Interface impementation above
	n1 := myints{7, 4, 8, 2, 9, 19, 12, 32, 2}
	fmt.Println("n1 (1):", n1)
	sort.Sort(n1)
	fmt.Println("n1 (2):", n1)

	/// Alternatively, use the sort.Reverse that returns Interface
	n2 := []int{8, 3, 88, 7, 18, 19, 17, 30, 29}
	fmt.Println("n2 (1):", n2)
	sort.Sort(sort.Reverse(sort.IntSlice(n2)))
	fmt.Println("n2 (2):", n2)
}
