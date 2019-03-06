/////////////////////////////////////////////////////////////////////////
// * The proof is in the pudding ////////////////////////////////////////
// * Until you've figured out how to photosynthesize, you have to eat ///
/////////////////////////////////////////////////////////////////////////
//ASCII to Integer

/*
48 0
49 1
50 2
51 3
52 4
53 5
54 6
55 7
56 8
57 9
*/

//Package strconv implements conversions to and from string representations of basic data types.
package main

import "fmt"

func main() {
	fmt.Println(myAtoi("  001122"))
}

func myAtoi(str string) int {
	length := len(str)
	if length == 0 {
		return 0
	}

	maxInt := 1<<31 - 1
	minInt := -maxInt - 1

	ret, v, i, flag := 0, 0, 0, 1

	for ; i < length; i++ {
		if str[i] == ' ' {
			continue
		}
		break
	}

	if i >= length {
		return 0
	}

	if str[i] == '-' {
		i++
		flag = -1
	} else if str[i] == '+' {
		i++
		flag = 1
	}

	for ; i < len(str); i++ {
		v = int(str[i] - '0')
		if v > 9 || v < 0 {
			return ret * flag
		}
		if (flag * ret) > (maxInt-v)/10 {
			return maxInt
		} else if (flag * ret) < (minInt+v)/10 {
			return minInt
		}
		ret = ret*10 + v
	}
	return ret * flag
}
