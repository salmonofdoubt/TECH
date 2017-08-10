function a(l, i){       // 3. this return here is now passed to c()  
    // l = [ 1, 2, 3, 3, 3, 4 ]
    // i = 2   
    // x = "s"                    
    function aa(x){             // a() runs a closure aa(), which takes x (example value) 
        l[i] = x                // and sets list element l[i] to x
    }
    // l = [ 1, 2, 's', 3, 3, 4 ]
    return aa                   // but it only returns this inner function aa, not a value!!!
}

function b(x, y){               // y needs to be a function..
    return (...args) => x(y(...args))
}

function c(fn){         // 3. run c(aa)
    // start from end of statement
    // (aa)      do this      do this  aa(arg, ...args), which should execute aa()
    return (arg) => (...args) => fn(arg, ...args)
    // execute aa() but we don't know what arg and ...args is.
}

function *g(iterable, fn){  // 7. c runs with g now
                            // not a pointer, a generator function, pausable
    for (let i = 2; i < iterable.length; i++){
        yield fn(i, iterable[i])  // yield pauses the function until it's called again
    }
}

                        // 0. one would argue foo takes a list, and a function
function foo(l, f){  
    var faa = c(a)(l)   // 2. run c with what a returns, which is func statement aa. 
                        // 4. Stick l into aa. 
                        //    var faa is a function       
    var fgg = c(g)(l)   // 6. run c again, with whatever g returns (a generator)
                        // 8. Stick l into the generator        
                        //    var fgg is a funtion 
    console.log()
    function bar(i, x) {
        //call b(faa(i), f) and stick that result into b as arg x
        b(faa(i), f)(x)
    } 
    //var bar = (i, x) => b(faa(i), f)(x) 

    for (let i of fgg(bar)){
    }
}

var list = [1,2,3,3,3,4]
var func = function(){return "ononono"} 

console.log("BEGIN:",list, func)
foo(list, func)         // 1. So let's call it
console.log("END:  ",list, func)