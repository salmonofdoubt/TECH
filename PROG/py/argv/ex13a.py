#!/usr/bin/env python
#encoding: utf-8

from sys import argv

def main():
	script, first, second, third = argv
	print "The script is called:", script
	print "Your 1st var is:", first
	print "Your 2nd var is:", second
	print "Your 3rd var is:", third

if __name__ == '__main__':
	main()