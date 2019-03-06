#!/usr/bin/env python

print '\nAverage 1\n'
# while loop to calculate average
count = 0
sum = 0
number = float

while number != 0:
    number = float(input("enter your numbers, finish with 0: "))
    if number != 0:
        count = count + 1
        sum = sum + number
print 'average: ', sum/count