input()
print('Test your module')
if __name__ == "__main__":
    print('testing modules ok (there are none)')

'''
Python modules are objects and have several useful attributes.
You can use this to easily test your modules as you 
write them.
Here's an example that uses the if__name__ trick.

if __name__ == "__main__":

- the if statement ends with a colon, and is followed by indented code. 
- Like C, Python uses == for comparison and = for assignment.
- Unlike C, Python does not support in−line assignment, 
- Modules are objects, and all modules have a built−in attribute __name__
- A module's __name__ depends on how it's used.
    - on import __name__ is the module's filename, without a directory path or file extension
    - as a standalone program, in which case __name__ will be a special default value, __main__. 

>>> import odbchelper 
>>> odbchelper.__name__ 
'odbchelper'

So design a test suite for your module within the module itself by putting it in this if statement. 
When you run the module directly, __name__ == __main__, so the test suite executes.
When you import the module, __name__ is something else, so the test suite is ignored.
This makes it easier to develop and debug new modules before integrating them into a larger program.
'''
    
print('\nEnd')


