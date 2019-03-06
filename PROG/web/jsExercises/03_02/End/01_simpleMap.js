// Learning Functional Programming with Javascript
// Chapter 03, Video 02, Exercise 01 **SOLUTION**
var _ = require("lodash")

var numbers = [ 1, 2, 3, 4, 5 ]
var numbersCubed = _.map(numbers, function(element) {
  return element * element * element
})

console.log(numbersCubed)
