//check https://cs.corp.google.com/piper///depot/google3/ops/nst/workflow/repair_automation/deviceoperations/modules/linecard/linecard_manager_arista.go

package main

import "fmt"

type myList []int

func (m *myList) add(i int) {
	*m = append(*m, i)
}

/*func (m *myList) remove(i int) error {
	if i-1 >= len(*m) {
		return errors.New("index too high")
	}
	*m = append((*m)[:(i-1)], (*m)[i:]...)
	return nil
}*/

func (m *myList) remove(i int) {
	*m = append((*m)[:i-1], (*m)[i:]...)
}

func (m myList) length() int {
	return len(m)
}

func main() {
	l := myList([]int{1, 6, 3, 8, 4, 2})
	(&l).add(10)
	fmt.Println(l)
	//	err := l.remove(5)
	//	if err != nil {
	//		fmt.Println(err)
	//	} else {
	l.remove(5)
	fmt.Println(l)
	//	}
	fmt.Println(l.length())
}
