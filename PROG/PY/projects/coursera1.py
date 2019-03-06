#!/usr/bin/env python
# encoding: utf-8

def computepay(h,r):
    cp = 0
    if h <= 40:
        cp = h*r
    elif h > 40:
        cp = 40 * r + (h-40)*r*1.5
    return cp

hrs = float(raw_input("Enter Hours:"))
rate = float(raw_input("Enter Rate:"))

p = computepay(hrs,rate)
print p





# if __name__ == '__main__':
#  main()


