package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", sroot)
	http.ListenAndServe(":8080", nil)
}

func sroot(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Welcome to the HYDRA software system")
}
