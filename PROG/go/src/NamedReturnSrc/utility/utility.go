package utility

/* NOTE:
package is called utility, so it must live under src/.../utility
without main, such packages are not the executable, that will be
the main() files which import packages such as this one here.
*/

// DoMaths uses named returns. The vars dont need :=, only =
func DoMaths(a, b int) (add, sub, mul, div int) {
	add = a + b
	sub = a - b
	mul = a * b
	div = a / b
	return
}
