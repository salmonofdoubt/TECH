#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by André Baumann on 2011-08-29.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def main():
  pass
  
def countdown(s):
  while s <= 0:
    print 'Blastoff!'
  else:
    print s
    countdown(s-1)

countdown(2000)

if __name__ == '__main__':
  main()

