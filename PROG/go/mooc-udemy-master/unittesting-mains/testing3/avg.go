package main

func main() {

}

func Avg(nos ...int) int {
	sum := 0
	for _, n := range nos {
		sum += n
	}
	if sum == 0 {
		return 0
	}
	return sum / len(nos)
}
