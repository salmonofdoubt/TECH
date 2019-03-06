- STRUCTURES

When declaring a structure without instances, you are creating a template. 
You do not actually declare any variables.
It is not until you create an instance of the structure that you declare a variable.

For this reason, you can leave a structure body external to any functions with no real effect on external memory. 
Many programmers put commonly used structure bodies with tags into header files, 
and then include these header files when they need to create an instance of the structure.