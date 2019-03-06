#!/usr/bin/env python
# encoding: utf-8
"""
Created by André Baumann on 2011-08-23.
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import sys
import os

def main():
	x = 'xxx'
	while x: 
		print x
		x = x[1:]
		  
	print '\n------\n'
	
	x = 16
	while x:
		x -= 1
		if x % 2 != 0: continue #prints all even numbers
		print x
		
	print '\n------\n'

	remain(36)
	exercise()
	
def remain(y):
	x = y / 2
	while x > 1:
		if y % x == 0: # remainder
			print y, 'has factor', x, '\n'
			break # skip else
			x = x-1
		else: # normal exit
			print y, 'is prime \n'
			sys.exit(0)
			
			
def exercise():
	count = 6
	number = 'number:'
	text = ['pos 1', 
					'pos 2',
					'pos 3',
					'pos 4',
					'pos 5',
					'pos 6'] 
	
	while count > 1:
		for i in range(len(text)):
			print number, count, text[i]
			count -= 1
		

if __name__ == '__main__':
 	main()

