#!/usr/bin/python

print 'This function creates a list.'

def makelist():
  a = []
  for i in range(1, 20):
    a.append(i)
    print 'appending', i, ':', a
  return a
  
makelist()


