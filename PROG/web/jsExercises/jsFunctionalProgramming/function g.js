
function *g(iterable, fn){  // 7. c runs with g now
                            // not a pointer, a generator function
    for (let i = 0; i < iterable.length; i++){
        console.log(fn)
        yield fn(i, iterable[i])  // yield expression
    }
}

var list = [1,2,3,3,3,4]
var func = function(){return "ononono", "ono"} 

g(list, func)
console.log(list)