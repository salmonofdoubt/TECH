#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by André Baumann on 2011-08-24.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

### Three functions that call each other
try:
  def a():
    b()
  def b():
    c()
  def c():
    1/0 # Attempt at division by zero, will raise exception
except ZeroDivisionError:
  print 'my exception occured'


### Run function a()
a()