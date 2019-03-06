#!/usr/bin/env python
# encoding: utf-8
"""
py4du_tmp.py

Created by André Baumann on 2011-08-23.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os


class NameTag:                # super class
  def __init__(self, myname): #__init___(self, always needed
    self.myname = myname
  def say(self):              # an actual method
    print "Hello, my name is", self.myname
    
class GeekNameTag(NameTag):   # a subclass, calling  superclass
                              # no new __init__ as its not to be overwritten
  def say(self):              # new method say that behaves differently
    print "The current value of my name is", self.myname
                              



#if __name__ == '__main__':
#	main()

