#!/usr/bin/env python

print '\nAverage 2\n'
# while loop to calculate average for a given amount of numbers
sum = 0
print'Enter several numbers then average them'
count = int(input("How many numbers? "))
curr_count = 0

while curr_count < count:
    curr_count = curr_count + 1
    print 'Number', curr_count
    number = float(input("Enter number: "))
    sum = sum + number
print 'average: ', sum/count