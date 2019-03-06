// Learning Functional Programming with Javascript
// Chapter 05, Video 02, Exercise 01

function add(x, y) {
  return x + y
}

function partiallyApply(func, x) {
  return function(y) {
    return func(x, y)
  }
}

var add5 = partiallyApply(add, 5)

console.log(add5(2))
