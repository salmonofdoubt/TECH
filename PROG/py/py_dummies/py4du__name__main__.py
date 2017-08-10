#!/usr/bin/env python
# encoding: utf-8
"""
py4du__name__main__.py

"""

def f(x):
  '''a small function'''
  y = 2**x
  return y

if __name__ == "__main__":
  '''and it\'s testcode'''
  
  print "testing, passing the value 8..."
  z = f(8)
  print "the function returns", z


