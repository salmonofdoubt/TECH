//main ...
package main

import (
	"FirstAppSrc/utility" //which doesnt live in pkg, but src folder
	"fmt"
)

func main() {
	fmt.Println("Hello Go world")
	utility.SayHello()
	utility.AndreSayHello()
}
