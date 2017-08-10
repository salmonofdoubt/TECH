// Learning Functional Programming with Javascript
// Chapter 02, Video 03, Exercise 01 **SOLUTION**
function doIf(condition, func) {
  if(condition) {
    func()
  }
}

const x = 1

doIf(x === 1, function() {
  console.log("x is equal to 1")
})
doIf(x === "Bananas", function() {
  console.log("x is equal to 'Bananas'")
})
doIf(x < 10 && x > 0, function() {
  console.log("x is between 0 and 10")
})
