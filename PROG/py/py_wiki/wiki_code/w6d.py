#!/usr/bin/env python
#6_Functions, understand local and global variables

a = 10
b = 15
e = 20

def a_fct(a):
    b = 100 + a
    d = 2 * a
    print ("In a_fct a = , a")
    print 'In a_fct b =', b
    print 'In a_fct d =', d
    print 'In a_fct e =', e
    return b + 10

c = a_fct(b)

print 'Global a = ', a
print 'Global b = ', b
print 'Global c = ', c
#print 'Global d = ', d
print 'Global e = ', e

