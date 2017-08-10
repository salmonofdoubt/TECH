/*

function b(...args) {
  return arguments;
}
console.log(b(1, 2, 3)); // { "0": 1, "1": 2, "2": 3 }
*/

/*
var multiply1 = function(x,y){
    return x * y
}

// var functionname       takes args     and does this
var multiply2       =     (x,y)          => { return x * y}
var multiply3       =     (x,y)          => x * y

console.log(multiply1(1,1))
console.log(multiply2(2,2))
console.log(multiply3(3,3))
*/

function b(x, y){
    console.log(x, y)
    console.log(...args)
    return (...args) => x(y(...args))       //evaluates y(with args) return all args 
}

console.log(b("a","c"))
