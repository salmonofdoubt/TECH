#!/usr/bin/env python
# encoding: utf-8
"""
Discription: 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
from sys import exit
import os


def list_stuff():
	some_things = "Apples Oranges Crows Telephone Light Sugar"
	print " 10 things is not yet 10 things..fixing it..\n"
	
	some_things = some_things.split(' ')
	print "1. some_things\t: %r" %some_things
	
	other_stuff = ["Day","Night","Song","Frisbee","Corn","Banana", "Girl", "Boy"]
	
	print "3. other_stuff\t: ", other_stuff
	
	while len(some_things) != 10:		#we pop other_stuff as long as stuff is not 10
		next_one = other_stuff.pop()	#next_one is the one that got popped
		print "4. Adding: ", next_one
		some_things.append(next_one)
		print "5. There is %d items now." %len(some_things)
		
	print "6. some_things\t: %r\n" %some_things
		
	print "7.\t\t:" , some_things[1]
	print "8.\t\t:" , some_things[1:]
	print "9.\t\t:" , some_things[-1]
	print "10.\t\t:", some_things[6:-1]
	
	print "11.\t\t:", some_things.pop()				# pops last e
	print "12.\t\t:", some_things.pop(3)			# pops 4th e
	print "13.\t\t:", ' '.join(some_things)		# some_things has now changed
	print "14.\t\t:", '#'.join(some_things)

def main():
	list_stuff()
	sys.exit(0) 

if __name__ == '__main__':
	main()