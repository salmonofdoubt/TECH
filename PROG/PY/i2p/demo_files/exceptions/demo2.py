#!/usr/bin/python2.6

try:
  num = raw_input('enter an int: ')

  print int(num) + 4
except ValueError:
  print 'invalid int'
