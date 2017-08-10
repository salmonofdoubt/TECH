#!/usr/bin/env python

print '\n1. A \'==\' exercise \n'
# Demonstrates use of the == operator using numbers
print 5 == 6

# Using variables
x = 8
y = 8
print x == y 

raw_input()

print '\n2. Guess \n'
#Guessing game

number = 120
guess = int
while guess != number:
    guess = int(input ("Guess my number: \n "))
    if guess > number:
        print 'Too high'
    elif guess < number:
        print 'Too low'
        
print '\n  Spot on! \n'







        