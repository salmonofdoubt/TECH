#!/usr/bin/env python
# encoding: utf-8
"""
b7other_modules.py

Created by André Baumann on 2011-12-11.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os
import random


def main():
	my_int = random.randint(1,10)
	print my_int
	
	my_float = random.random() 
	print my_float
	
	names = ['albert', 'satish', 'saurabh']
	winner = random.choice(names)
	print winner + ' just won 1 million rupeees!'

if __name__ == '__main__':
	main()

