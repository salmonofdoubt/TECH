#!/usr/bin/env python
#6_Functions AREA ***with menue***


def print_options():
    print("Options:")
    print(" 'p' print options")
    print(" 'r' calculate rectangular area")
    print(" 'c' calculate cicular area")
    print(" 'q' quit the program")

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

choice = 'p'
while choice != 'q':
    if choice == 'r':
        w = positive_input('Width: ')
        h = positive_input('Height: ')
        print('Width =', w, 'Height =', h)
        print('Area of rectangular =', rec_area(w, h))
    elif choice == 'c':
        r = positive_input('Radius: ')
        print('Radius =', r)
        print('Area of circle =', circle_area(r))
    elif choice == 'p':
        print_options()
    choice = input('option: ')
