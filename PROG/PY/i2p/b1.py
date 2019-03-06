#!/usr/bin/env python
# encoding: utf-8
"""
STD BOILERPLATE
Created by André Baumann on 2011-08-23.
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import sys
import os

def main():
	print sys.argv[0:5]
	
	old_str = '12super'
	new_str = old_str[0:5].upper()
	print new_str
	
	a = 10
	b = 3
	c = a % b
	print c

	str1 = 'I have'
	int1 = 99
	str2 = 'bottles of beer'
	print str1 +' '+str(int1)+' '+str2
	
	str1 = '1'
	int1 = 99
	print int(str1)+int1
	
  #sys.exit(0) 
if __name__ == '__main__':
	main()