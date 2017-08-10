package main

import (
	"fmt"
	"runtime"
)

func main() { //switch statements

	inc := incrementer()
	for i := 0; i < 2; i++ {
		fmt.Println(inc()) // effectively executes inc() 2 times, so inc() == 2
	}

	switch i := inc(); { // inc() == 3
	case i < 0:
		fmt.Println("i is a negative number")
	case i == 0:
		fmt.Println("i is zero")
	default:
		fmt.Println("i is a positive number")
	}

	switch i := inc(); { // awe, inc() executed again, i is now 4
	case i < 4:
		fmt.Println("sw i < 4:", i)
	case i == 4:
		fmt.Println("sw i == 4:", i)
		fallthrough // i is still 4, but fall through the next test, right to it's action
	case i == 5: // so this is not testet
		fmt.Println("sw i == 5:", i) // but the action is still taken. Not sure where that's useful..
		fallthrough
	default:
		fmt.Println("sw default:", i)
	}

	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.", os)

		defer fmt.Println("Exiting function.... ")
		fmt.Println("Entering function")

	}
}

func incrementer() func() int { //outer func, returns a func
	i := 0
	return func() int { //inner function - the closure, which has access to i
		//the new value of it will be retained
		i++
		return i
	}
}
