#!/usr/bin/env python
# encoding: utf-8
"""
Discription: 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
import os


def for_loop(length, steps):
	i = 0
	numbers = []
	
	for i in range(length):
		print "top i: %d" %steps
		numbers.append(i)
 
		print "Numbers: ", numbers
		print "bottom i: %d" %i
	
	print "\nNumbers: "
	
	for num in numbers:
		print num
		
			
def main():
	length = int(raw_input('> length: '))
	steps = int(raw_input('> steps: '))
	for_loop(length, steps)
	
if __name__ == '__main__':
	main()