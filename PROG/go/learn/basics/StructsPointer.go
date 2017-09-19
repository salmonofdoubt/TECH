package main

import "fmt"

type artist struct {
	Songs int
}

func newRelease(a artist) int {
	a.Songs++
	return a.Songs

}

func newReleasePointer(a *artist) int {
	a.Songs++
	return a.Songs
}

func main() {
	o := artist{
		Songs: 3,
	}
	fmt.Printf("before: %d songs\n", o.Songs)
	fmt.Printf("now %d songs\n", newRelease(o))
	fmt.Printf("after: %d songs\n", o.Songs)

	fmt.Printf("before: %d songs\n", o.Songs)
	fmt.Printf("now %d songs\n", newReleasePointer(&o)) //or, object defined o := &Artist ...
	fmt.Printf("after: %d songs\n", o.Songs)

}
