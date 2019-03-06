// main yet another main in same dir, I know!
package main

import (
	"fmt"
	"math/rand"
	"time"
)

type customRand struct { // outer type
	*rand.Rand //inner type, imported. Contains unexported fields though?
	count      int
}

func NewCustomRand(i int64) *customRand {
	return &customRand{
		Rand:  rand.New(rand.NewSource(i)),
		count: 0,
	}
}

func (cr *customRand) GetCount() int {
	return cr.count
}

func (cr *customRand) RandRange(min, max int) int {
	cr.count++                         // let's do some work on a field on the outer type
	return cr.Rand.Intn(max-min) + min // belongs to inner struct, using inner name
}

// Promoting: Using this method here we get GetCount 2 below. Because the method is local.
// Not using it, GetCount is 1. We are then using Intn() from the rand package,so we are not using our T customRand.
// So priority will be given to local method with same name, but different types.
func (cr *customRand) Intn(n int) int {
	cr.count++
	return cr.Rand.Intn(n) + 1 // we are in fact still using the Rand package.
}

func main() {
	cr := NewCustomRand(time.Now().UnixNano())
	fmt.Println("RandRange:", cr.RandRange(5, 30))
	fmt.Println("Promoting Intn:", cr.Intn(10)) // promoting: using a struct method from the original package: here random number btw 0 and 9
	fmt.Println("GetCount:", cr.GetCount())
}
