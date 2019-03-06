function myFunction(p1) {
    return (arg) => (...args) => fn(arg, ...args);              // The function returns the product of p1 and p2
}

var p1 = function(x,y) {return x*y}
console.log(myFunction(p1))




/*
var foo = function fsoo() {
    console.log(foo === foo);  
};
foo();
*/

/*
var i = 1;
var k = ++i;  // pre-increment:  i == 2, k == 2
console.log(k, i)

var i = 1;
var k = i++;  // post-increment: i == 1, k == 2
console.log(k, i)
*/


/*
function x() {
  y = 1;      // Undeclared, so Global. Throws a ReferenceError in strict mode
  var z = 2;  // declared, so Local.
}

x();
console.log(y); // logs "1" 
console.log(z); // Throws a ReferenceError: z is not defined outside x
*/


/*
function sayHello(name) {
  var text = 'Hello ' + name; // local variable
  function greet() { 
    console.log(text)
  } //anonymous function, inside a function creates a closure
  return greet               // return that function
}

var x = sayHello('Andre');    // assignment assign x to a function that returns a function
x();                          // executes it on one deeper indendation, hence logs "Hello Andre"

var y = sayHello('John')()    // y is also executed 

sayHello('Bert')()            // same thing, more concise
*/


/*
// again braces make all the difference 
doSomething()   // runs the statement, nothing to see 
doSomething()() // executes the statement, i.e. makes it the return value "Ho", not just the entire statement

function doSomething(){
  return function(){
    console.log("Ho")
  }
}
*/

/*function doIf(condition, func) {
  if(condition) {
    func()
  }
}

const x = 1

    // a bool, func
doIf(x === 1, function() {
  console.log("x is equal to 1")
})
doIf(x === "Bananas", function() {
  console.log("x is equal to 'Bananas'")
})
doIf(x < 10 && x > 0, function() {
  console.log("x is between 0 and 10")
})
*/
