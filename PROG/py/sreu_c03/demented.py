#!/usr/bin/env python
# encoding: utf-8
"""
demented.py

Created by André Baumann on 2011-12-14.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def sillystrip(f):
    if f.__doc__:
        f.__doc__ = "Your function has been hacked!"
    else:
        f.__doc__ = "You should always have a docstring."
    return f

@sillystrip
def square( x ):
    """could also be a triangle"""
    return x * x

def _test():
    frank = 2
    joe = square (frank)  # frank is kinda square
    print("Hello Joe, Frank here.")
    print(square.__doc__)
        

if __name__ == "__main__":
    _test()