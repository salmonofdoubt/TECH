package main

func main() {
}

/*
Organise code
----------------------
* Files being bundled in dirs

main
  main.go      << declared as "package main" in first line
               << followed by "import stringutil" (or FQN)

stringutil     << no exes here, this is the package, to be imported into package main)
  name.go      << all declared as "package stringutil" in first line
  reverse.go
  reverseTwo.go

Lower / upper case
----------------------
 Say, package stringutil == folder stringutil
 scope then:
   Lower case function is within that package,not exported, not visible
   Upper case is exported outside that package, say if used in main.go
*/
