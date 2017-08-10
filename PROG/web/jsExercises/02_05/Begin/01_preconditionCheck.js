// Learning Functional Programming with Javascript
// Chapter 02, Video 05, Exercise 01

function printMessageNTimes(n, message) {
  if (n != null && typeof n === 'number') {
    if (message != null && typeof message === 'string') {
      for (var i = 0; i < n; i++) { console.log(message) }
    }
  }
}

function getNthLetter(n, string) {
  if (n != null && typeof n === 'number') {
    if (string != null && typeof string === 'string') {
      return string.charAt(n)
    }
  }
}

function getSubstringOfLength(n, string) {
  if (n != null && typeof n === 'number') {
    if (string != null && typeof string === 'string') {
      return string.substring(0, n)
    }
  }
}

printMessageNTimes(4, "Banana") // prints "Banana Banana Banana Banana"
getNthLetter(2, "Javascript") // 'v'
getSubstringOfLength(5, "Hello and welcome") // "Hello"
