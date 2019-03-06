#!/usr/bin/env python
# encoding: utf-8
"""
ex15.py

Created by André Baumann on 2012-01-10.
Copyright (c) 2012 __MyCompanyName__. All rights reserved.
"""

from sys import argv

def main():
	script, filename = argv

	txt = open(filename)
	print "Here's your file: %r" %filename
	print txt.read()

	print "Asking for the file again:"
	file_again = raw_input("> ")
	txt_again = open(file_again)
	print txt_again.read()


if __name__ == '__main__':
	main()


