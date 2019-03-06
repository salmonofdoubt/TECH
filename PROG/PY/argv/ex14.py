#!/usr/bin/env python
# encoding: utf-8
"""
ex14.py

Created by André Baumann on 2011-12-30.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

from sys import argv

def main():
	script, user_name = argv
	
	print "Hi %s, I am the %s script." %(user_name, script)
	print "Do you like me %s?" %user_name
	likes = raw_input(prompt)
	
	print "Where do you live %s?" %user_name
	lives = raw_input(prompt)
	
	print """
	Alright, so you said %r about liking me.
	You live in %r. Not sure where that is.
	""" %(likes, lives)
	
if __name__ == '__main__':
	main()

