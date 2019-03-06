// Learning Functional Programming with Javascript
// Chapter 03, Video 05, Exercise 01 **SOLUTION**
var _ = require("lodash")

var shoppingList = [
  { name: "Eggs",    price: 4.99 },
  { name: "Milk",    price: 3.99 },
  { name: "Bananas", price: 2.79 },
  { name: "Beer",    price: 6.99 }
]

var totalCost = _.reduce(shoppingList, function(acc, item) {
  return acc + item.price
}, 0)

console.log(totalCost)
