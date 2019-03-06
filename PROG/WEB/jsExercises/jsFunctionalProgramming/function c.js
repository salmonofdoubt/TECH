
function c(fn){         // 3. run c(aa)
    // start from end of statement
    // (aa)      do this      do this  aa(arg, ...args), which should execute aa()
    return (arg) => (...args) => fn(arg, ...args)
    // execute aa() but we don't know what arg and ...args is.

}




