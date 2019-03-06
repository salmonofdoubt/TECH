#!/usr/bin/env python
# encoding: utf-8
"""
openfiles.py

Created by André Baumann on 2011-12-11.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os


def main():
	
	read()
	write()
	append()
	read()
	reset()
	
def read():
	my_file = open('test.txt')			# r,w,a
	while True:
		line =  my_file.read()			
		if not line: break
		print(line[:])
	
	
def write():
	write_str = '-- Writing new -- '
	my_file = open('test.txt', 'w')			
	my_file.write(write_str)
	
def append():
	write_str = '-- Appending --'
	my_file = open('test.txt', 'w')			
	my_file.write(write_str)

def reset():
	write_str = '-- Original content --'
	my_file = open('test.txt', 'w')			
	my_file.write(write_str)

if __name__ == '__main__':
	main()

