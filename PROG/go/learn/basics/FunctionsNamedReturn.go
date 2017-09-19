package main

import "fmt"

func location(name, city string) (region, continent string) {

	switch city {
	case "Los Angeles", "LA", "Santa Monica":
		region, continent = "California", "North America"
	default:
		region, continent = "Unknown", "Unknown"
	}
	return
}

func main() {
	region, continent := location("Matt", "SSanta Monica")
	fmt.Printf("Matt lives in %s, %s", region, continent)
}
