#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by André Baumann on 2011-08-24.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

sets = raw_input('')

def uniq(input):
  prev = object()
  for word in input:
    if word != prev:
      yield word
    prev = word

print myinput
uniq(myinput)
print myinput

