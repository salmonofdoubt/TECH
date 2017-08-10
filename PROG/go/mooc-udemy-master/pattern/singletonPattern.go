package main

import (
	"fmt"
	"net/http"
	"singletonPattern/hlogger"
)

func main() {
	logger := hlogger.GetInstance()
	logger.Println("Starting websever")

	http.HandleFunc("/", sroot)
	http.ListenAndServe(":8080", nil)
}

func sroot(w http.ResponseWriter, r *http.Request) {
	logger := hlogger.GetInstance()
	logger.Println("Starting websever again")
	fmt.Fprintf(w, "Welcome to the HYDRRRA software system")
	logger.Println("Received HTTP request on root url")
}
