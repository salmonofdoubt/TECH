#!/usr/bin/env python
# encoding: utf-8
"""
Discription: lists, ordinals, cardinals
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
import os


def my_list():
	animals = ['bear','tiger','pengiun','zebra',
	 					 'bear','tiger','pengiun','zebra']	#ordinal numbers, as order 
																								#matters

	global appendix
	appendix = 0
	
	for i in range(len(animals)):
		if i == '0' or i == '4'	or i == '5' or i == '6' or i == '7' or i == '8' or i == '9':
			appendix = 'th' 
		elif i == 1:
			appendix = 'st'
		elif i == 2:
			appendix = 'nd'
		elif i == 3:
			appendix = 'rd'
		
		cardinal = i+1

		print "%d%s animal (cardinal %d): %r" %(i, appendix, cardinal, animals[i])
	
def main():
	my_list()
	
if __name__ == '__main__':
	main()