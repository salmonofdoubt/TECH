#!/usr/bin/env python
#6_Functions

print '\n abs value without a function \n'
raw_input("Press key")

a = input("Enter 1st no: ")
b = input("Enter 2nd no: ")

if a < 0:
    a = -a
if b < 0:
    b = -b
if a == b:
    print 'The abs values of', a, 'and', b, 'are equal'
else:
    print 'The abs values of', a, 'and', b, 'are different'
    
raw_input("Press key")


print '\n abs value using a function \n'
raw_input("Press key")

a = input("Enter 1st no: ")
b = input("Enter 2nd no: ")

def abs_value(n):
    if n < 0:
        n = -n
    return n

if abs_value(a) == abs_value(b):
    print 'The absolute values of', a, 'and', b, 'are equal'
else:
    print 'The absolute values of', a, 'and', b, 'are different'
    
    


