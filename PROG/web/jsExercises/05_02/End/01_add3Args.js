// Learning Functional Programming with Javascript
// Chapter 05, Video 02, Exercise 01 **SOLUTION**

function add(x, y, z) {
  return x + y + z
}

function partiallyApply(func, x) {
  return function(y, z) {
    return func(x, y, z)
  }
}

var add5 = partiallyApply(add, 5)

console.log(add5(2, 3))
console.log(add(5, 2, 3))
