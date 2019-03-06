#!/usr/bin/env python
#6_Functions AREA (no menue)

def hi():
    print ("Hi!")

def welcome(name):
    print ("Welcome", name)
    
def rec_area(width, height):
    return width * height

def circle_area(radius):
    return 3.14159 * radius**2

def positive_input(prompt): 
    n = float(input(prompt))
    while n <= 0:
        print("must be positive")
        n = float(input(prompt))
    return n

#Program starts here

hi()
name = input('Your name: ')
welcome(name)

w = positive_input('Width: ')
h = positive_input('Height: ')
r = positive_input('Radius: ')


print('Width =', w, 'Height =', h, 'Radius =', r)
print('Area of rectangular =', rec_area(w, h))
print('Area of circle =', circle_area(r))



