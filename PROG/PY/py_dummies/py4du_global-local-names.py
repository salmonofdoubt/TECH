#!/usr/bin/env python
# encoding: utf-8

book = 'man\'s best friend'
print 'book outisde the function: ', book

def func():
  '''testing local vs global names'''
  book = 'too dark to read'
  print 'book inside a function: ', book

func()
'''execute the function'''

print 'and here is the book outside the function: ', book


  

  


