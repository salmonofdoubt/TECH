#!/usr/bin/env python
# encoding: utf-8
"""
ex17.py copy one file to another
Created by André Baumann 2011
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import time
from sys import argv

script, input_file = argv

def open_file():
	curr_file = open(input_file)
	return curr_file
	
def print_all(curr_file):
	print "File content:\n"
	print curr_file.read()

def rewind(curr_file):
	print "Rewind tape...\nPosition / Bytes to start seek is hardcoded (4)\n"
	curr_file.seek(4)								#cant pass var to seek it seems

def print_line(line_count, f):
	print line_count, f.readline()

def main():
	
	curr_file = open_file()
	
	print_all(curr_file)

	rewind(curr_file)

	lines = raw_input("No. of lines to print: ")
	for x in range(int(lines)):			#lines is in fact a string, so intergerize it!
		print_line(x, curr_file)
		time.sleep(1)

if __name__ == '__main__':
	main()


