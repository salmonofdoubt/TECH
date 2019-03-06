#!/usr/bin/env python
# 12_Modules

from random import randint
number = randint(0,99)
guess = 0
 
while guess != number: 
    guess = int(input ("Guess a number: "))
    if guess > number:
        print("Too high")
    elif guess < number:
        print("Too low")
 
print("Just right")

