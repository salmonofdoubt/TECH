package main

/*
author: abaumann@google.com
From go/gonotes 07/02/2017, HWK 07/02/2017

Create the test environment below. Contents of the files in parentheses.
Dir1
    file1 ("This is the content of the file")
    file2 ("The content of this file is different")
    Dir2
    Dir3
        file3 ("This is the content of the file")
        file4 ("This is another file")
        file5 ("Yet another file!!!!")
Dir4
    file6 ("This is the last one")
Dir5
    file7 ("This is the content of the file")
    file8 ("This is another file")

Delete the test environment.

Based on the test environment. Find duplicates.
Keep one copy of the file and create Hardlinks for the copies.
}
*/

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
)

//global vars
var fileMap = map[string]string{}

// check() is checking for errors and used repeatedly
func check(e error) {
	if e != nil {
		panic(e)
	}
}

//create dirs
func createDirs(dirs []string) {
	for i := range dirs {
		os.Mkdir(dirs[i], 777)
	}
}

func createFiles(files []string) {
	for i := range files {
		f, err := os.Create(files[i])
		check(err)
		defer f.Close()
	}
}

func writeToFiles(content []byte, files ...string) {
	for i := range files {
		err := ioutil.WriteFile(files[i], content, 0777)
		check(err)
	}
}

func main() {

	// dirs is a slice of string with directory names
	var dirs = []string{
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/",      //dir[0]
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir1/", //dir[1]
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir2/",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir3/",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir4/",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir5/",
	}

	// files is a slice of string with file names.
	var files = []string{
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir1/file1", //files[0]
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir1/file2", //files[1]
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir3/file3",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir3/file4",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir3/file5",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir4/file6",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir5/file7",
		"/usr/local/google/home/abaumann/workspace/ra/ArtEnv/Dir5/file8",
	}

	// Some different file content in byte form so to satisfy ioutil.WriteFile().
	c137 := []byte("This is the content of the file")
	c2 := []byte("The content of this file is different")
	c48 := []byte("This is another file")
	c5 := []byte("Yet another file!!!!")
	c6 := []byte("This is the last one")

	//calling respective functions to create environment
	createDirs(dirs)

	createFiles(files)

	writeToFiles(c137, files[0], files[2], files[6])
	writeToFiles(c2, files[1])
	writeToFiles(c48, files[3], files[7])
	writeToFiles(c5, files[4])
	writeToFiles(c6, files[5])

	// filepath.Walk runs through every dir and with parameters returned from walkFunc
	filepath.Walk(dirs[0], walkFunc)

	// Print global fileMap results
	fmt.Println("\n FYI: Files and their content under dir 'ArtEnv':")
	for fileMapKey := range fileMap {
		fmt.Println(fileMapKey, "|", fileMap[fileMapKey])
	}

	// Now identify duplicates
	var dup []string
	var seen = map[string]string{}

	for fileMapKey := range fileMap { //cannot yet iterate through seen
		for seenKey := range seen {
			if fileMap[fileMapKey] != seen[seenKey] {
				fmt.Println("of course", seen)
			}
		}
	}

	for i := range dup {
		fmt.Println("DUP:", i)
	}

	for k, v := range seen {
		fmt.Println("SEEN:", k, "|", v)
	}
}

// implement the walk func, which filepath.Walk calls repeatedly
func walkFunc(root string, info os.FileInfo, err error) error {
	if !info.IsDir() { //so if a file
		f, _ := ioutil.ReadFile(root)
		fs := string(f)
		fileMap[root] = fs //k v becomes fullfilename and filecontent
	}
	return nil
}
