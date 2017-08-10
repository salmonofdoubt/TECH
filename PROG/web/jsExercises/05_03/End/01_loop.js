// Learning Functional Programming with Javascript
// Chapter 05, Video 03, Exercise 01 **SOLUTION**

function loop(i) {
  console.log("i is " + i)
  if (i < 10) {
    loop(i + 1)
  }
}

loop(0)
