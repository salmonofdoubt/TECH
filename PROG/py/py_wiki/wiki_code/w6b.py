#!/usr/bin/env python
#6_Functions

def hi():
    print 'Hi from function'
    
def hi2(firstname, surname):
    print 'Hi',firstname, surname,'from function'
 
def area(width, height):
    return width * height

#calling the functions in different ways:

hi()
hi2("Andre", "Baumann")

w = 4
h = 5

print 'width =', w, 'height =', h, 'area =', area(w, h)





