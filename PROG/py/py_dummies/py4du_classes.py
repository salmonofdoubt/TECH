#!/usr/bin/env python
# encoding: utf-8
"""
in interative mode
"""

class Lab:
  weight = 60
  def retrieve(self, thing):
    return(thing)

fido = Lab()        # creating a class instance
y = len('mystring') # calling a function
      

type(fido)
#<type 'instance'>
type(y)
#<type 'int'>
type (Lab)
#<type 'classobj'>
type(len)
#¯type 'builtin_function_or_method'>


#if __name__ == '__main__':
#  main()

