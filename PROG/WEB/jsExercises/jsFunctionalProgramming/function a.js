function aa(x){ 
        l = [1, 2,3,3,3,4]                // a() runs aa() with x as arg, but what is x??? 
        i = 2
        console.log(l, i)
        l[i] = x                // set l[i] to x, which is undefined
        console.log(l[i])       
    } 
aa("s")
console.log(l, i)

/*

function a(l, i){               // a() takes two args l list, i iteration
    function aa(x){             // a() runs aa() with x as arg, but what is x??? 
        l[i] = x                // set l[i] to x, which is undefined
        console.log(l[i])       
    }
    console.log(aa)
    return aa                   // and returns this !!!function!!! aa
}

var l = [1,3,5] 
var i = 2
a(l,i)            // [Function: aa]
console.log(l,i)

*/