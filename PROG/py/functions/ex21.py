#!/usr/bin/env python
# encoding: utf-8
"""
some more on functions
"""
import sys

def add(a,b):
	print "ADDING %r + %r" %(a,b)
	return a + b
	
def sub(a,b):
	print "SUBTRACTING %r - %r" %(a,b)
	return a - b

def mul(a,b):
	print "MULTIPLYING %r * %r" %(a,b)
	return a * b
	
def div(a,b):
	print "DIVIDING %r / %r" %(a,b)
	return a / b

def main():
	
	print "Select operation:\n1: ADD\n2: SUB\n3: MUL\n4: DIV\n"
	options = int(raw_input())
	print "Two integers:"
	int1 = int(raw_input())
	int2 = int(raw_input())
	 
	if (options == 1):
		result = add(int1, int2)
		print result
	if (options == 2):
		result = sub(int1, int2)
		print result
	if (options == 3):
		result = mul(int1, int2)
	if (options == 4):
		result = div(int1, int2)
		print result

if __name__ == '__main__':
	main()


