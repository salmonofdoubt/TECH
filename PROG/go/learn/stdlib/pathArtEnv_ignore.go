package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
)

func printFile(ignoreDirs []string) filepath.WalkFunc {
	return func(path string, info os.FileInfo, err error) error {
		if err != nil {
			log.Print(err)
			return nil
		}
		if info.IsDir() {
			dir := filepath.Base(path)
			for _, d := range ignoreDirs {
				if d == dir {
					return filepath.SkipDir
				}
			}
		}
		fmt.Println(path)
		return nil
	}
}

func main() {
	log.SetFlags(log.Lshortfile)
	dir := os.Args[1]
	ignoreDirs := []string{".bzr", ".hg", ".git"}
	err := filepath.Walk(dir, printFile(ignoreDirs))
	if err != nil {
		log.Fatal(err)
	}
}
