#!/usr/bin/env python
# 16

#the int() function is unhappy with the number @#& (as well it should be).
#when we run the new program and give it @#& it tells us "That was not a number."
#and continues with what it was doing before.


print("Type Control C or -1 to exit")
number = 1
while number != -1:
    try:
        number = int(input("Enter a number: "))
        print("You entered:", number)
    except ValueError:
        print("That was not a number.")
