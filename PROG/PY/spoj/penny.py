#!/usr/bin/python2.4 -tt
# Copyright 2008 Google Inc. All Rights Reserved.

"""Mimic pyquick exercise -- optional extra exercise.



"""
__author__ = 'nparlante@google.com (Nick Parlante)'

import random
import sys


def A(arg1, arg2):
  """Returns mimic dict mapping each word to list of words which follow it."""
  # +++your code here+++
  return None


def B(arg1, arg2):
  """Given mimic dict and start word, prints 200 random words."""
  # +++your code here+++
  print('implement me')


# Provided main(), calls MimicDict() and Mimic()
def main():

	seq = ['TTT', 'TTH', 'THT', 'THH', 'HTT', 'HTH', 'HHT', 'HHH']
	strings = raw_input("")
	inputs = []
	
	count = 0
	for x in xrange(len(string) - len(seq) + 1):
		if string[x:x+len(seq)] == seq:
			count += 1
	print('%d', count)
	return count


if __name__ == '__main__':
  main()




'''



#!/usr/bin/env python
# encoding: utf-8
"""
penny.py
penny's game
Created by André Baumann on 2011-08-24.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def main():
	seq = ['TTT', 'TTH', 'THT', 'THH', 'HTT', 'HTH', 'HHT', 'HHH']
	string = raw_input('')
	inputs = []
	
	count = 0
	for x in xrange(len(string) - len(seq) + 1):
  	if string[x:x+len(seq)] == seq:
    	count += 1
  print(%d, count)
	return count
	
	


	
	sets = raw_input('')
	if (sets < 1 or sets > 1000): 
		compare(line1)
	else:
		sys.exit(1)
	
	iterations = int(raw_input'')
	

	line = raw_input('')
		
	
def compare(string, line):
  print('compare')



	def function(string, str_to_search_for):
	      

	function('1011101111','11')
	returns 5
	
	
	import re
	>>> aString = 'this is a string where the substring "is" is repeated several times'
	>>> print [(a.start(), a.end()) for a in list(re.finditer('is', astring))]
	[(2, 4), (5, 7), (38, 40), (42, 44)]
	
'''