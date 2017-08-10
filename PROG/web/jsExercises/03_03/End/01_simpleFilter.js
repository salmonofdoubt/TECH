// Learning Functional Programming with Javascript
// Chapter 03, Video 03, Exercise 01 **SOLUTION**
var _ = require("lodash")

var numbers = [ 1, 2, 3, 4, 5 ]
var evensFromNumbers = _.filter(numbers, function(element) {
  return element % 2 === 0
})

console.log(evensFromNumbers)
