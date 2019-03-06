#!/usr/bin/env python
# encoding: utf-8
"""
ex17.py copy one file to another
Created by André Baumann 2011
Copyright (c) Google Inc. 2011. All rights reserved.
"""

from sys import argv
from os.path import exists
import time

def main():
	script, from_file, to_file = argv
	
	print "Copying from %s to %s" % (from_file, to_file)

	indata = open(from_file, 'r').read()
	# open file, read content. 
	# Can't close as indata is now read in data, not a file object.
	
	time.sleep(1)

	print "Lenght of input file: %d bytes." %len(indata)
	#print "Content: %r." %indata

	print "Output file exists: %r" % exists(to_file)
	print "Continue: RETURN, Abort: CTRL-C."
	raw_input()
	
	outdata = open(to_file, 'w')
	outdata.write(indata)
	
	time.sleep(1)
	print "Done."
	outdata.close()

if __name__ == '__main__':
	main()









