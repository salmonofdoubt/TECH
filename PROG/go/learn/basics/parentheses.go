///////////////////////////////
// find matching parentheses //
///////////////////////////////

package main

import "fmt"

func main() {
	var str string
	fmt.Println("Enter string with parenthesis: ")
	fmt.Scan(&str)
	parentheses(str)
}

func parentheses(s string) {
	var stack []int

	for pos := range s {
		if string(s[pos]) == "(" {
			stack = append(stack, pos) //push pos on stack
		} else {
			if string(s[pos]) == ")" && stack == nil {
				fmt.Println("error")
			} else {
				if string(s[pos]) == ")" {
					//last stack pos and current pos
					fmt.Println(stack[len(stack)-1], pos)
					//and pop one from stack [low:high]
					stack = stack[:len(stack)-1]

				}
			}
		}
	}
	fmt.Println()
}
