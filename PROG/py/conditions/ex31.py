#!/usr/bin/env python
# encoding: utf-8
"""
Discription: nested else-if 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
import os

def data_input():
	while True:
		door = raw_input("> Enter through dark room door '1' or '2' ?:\n> ")
		if door == '1':
			choice = raw_input("> Door 1: 'lab' or 'cellar' ?:\n> ")
			if choice == 'lab' or choice == 'cellar':
				print "lab or cellar: Access granted.\n"
			else:
				print "a. No such destination. Goodbye.\n"

		elif door == '2':
			choice = raw_input("> Door 2: 'store' or 'roof' ?:\n> ")
			if choice == 'store' or choice == 'roof':
				print "store or roof: Access granted\n."
			else:
				print "b. No such destination. Goodbye.\n"
				
		else:
			print "No such door."
	
def main():
	data_input()
	
	
	
if __name__ == '__main__':
	main()
