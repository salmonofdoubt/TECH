#!/usr/bin/env python
# encoding: utf-8
'''
- std boilerplate - 
Created by André Baumann 2011
Copyright (c) Google Inc. 2011. All rights reserved.
'''
from sys import argv
import time

def main():
	script, filename = argv
	 
	print 'Opening file %r.' %filename
	target = open(filename, 'r')	#open read
	print "Current content:"
	time.sleep(2)
	for line in target:
		print line

	raw_input('> Erasing content? \n> Enter to contiue, ctl+C to abort')
	target = open(filename, 'w')	#open write
	target.truncate()							#erase
	print "Erasing content..."
	time.sleep(1)
	print "Done.\n"
	
	print "Add new content."
	line1 = raw_input("line 1: ")
	line2 = raw_input("line 2: ")
	line3 = raw_input("line 3: ")
	
	print "writing... closing..."
	target.write(line1+'\n')			#write
	target.write(line2+'\n')
	target.write(line2+'\n')
	time.sleep(1)
	target.close()								#close


if __name__ == '__main__':
	main()









