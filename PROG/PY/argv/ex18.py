#!/usr/bin/env python
# encoding: utf-8
"""
ex17.py copy one file to another
Created by André Baumann 2011
Copyright (c) Google Inc. 2011. All rights reserved.
"""

from sys import argv

def print_two(*args):
	arg1, arg2 = argv
	print "arg1: %r, arg2: %r" %(arg1, arg2)

def cheese(cheese_count, boxes):
	print "No. of cheeses: %d." %cheese_count
	print "No. of boxes: %d." %boxes
	 

def main():
	print_two()
	cheese(7, 5)
	
	numberofcheeses = 120
	numberofboxes = 110
	cheese(numberofcheeses, numberofboxes)

	
if __name__ == '__main__':
	main()









