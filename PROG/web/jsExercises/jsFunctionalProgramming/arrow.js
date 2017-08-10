
// ES5
// var name     is function    and does this
var multiply = function(x,y) {
  return x * y
}

//ES6
// var name     is func      and does this
var multiply =     (x,y)  => { return x * y}






var selected = allJobs.filter(function (job) {
  return job.isSelected();
});

// ES6
var selected = allJobs.filter(job => job.isSelected());
When you just need a simple function with one argument, the new arrow function syntax is simply Identifier => Expression. You get to skip typing function and return, as well as some parentheses, braces, and a semicolon.

(I am personally very grateful for this feature. Not having to type function is important to me, because I inevitably type functoin instead and have to go back and correct it.)

To write a function with multiple arguments (or no arguments, or rest parameters or defaults, or a destructuring argument) you’ll need to add parentheses around the argument list.