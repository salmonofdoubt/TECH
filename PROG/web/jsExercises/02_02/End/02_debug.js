// Learning Functional Programming with Javascript
// Chapter 02, Video 02, Exercise 02 **SOLUTION**
const DEBUG_MODE_ENABLED = false

var debug

if (DEBUG_MODE_ENABLED) {
  debug = printDebugMessage
} else {
  debug = doNothing
}

// ...

debug("Some debug message")

// ...

function printDebugMessage(message) {
  console.log("DEBUG: " + message)
}

function doNothing() { }
